#include <bits/stdc++.h>
using namespace std;

class Job {
   public:
    int start;
    int finish;
    int profit;
};

int binarySearch(Job jobs[], int index) {
    int low = 0;
    int high = index - 1;

    while (low <= high) {
        int mid = (low + high) / 2;
        if (jobs[mid].finish <= jobs[index].start) {
            if (jobs[mid + 1].finish <= jobs[index].start)
                low = mid + 1;
            else
                return mid;
        } else
            high = mid - 1;
    }

    return -1;
}

bool comp(Job a, Job b) {
    return a.finish < b.finish;
}

int getMaxProfit(Job jobs[], int n) {
    sort(jobs, jobs + n, comp);

    int table[n];
    table[0] = jobs[0].profit;

    for (int i = 1; i < n; ++i) {
        int incl = jobs[i].profit;
        int idx = binarySearch(jobs, i);
        if (idx != -1)
            incl += table[idx];
        table[i] = max(table[i - 1], incl);
    }

    return table[n - 1];
}

int main() {
    Job arr[] = {{1, 3, 20}, {2, 5, 20}, {3, 10, 100}, {4, 6, 70}, {6, 9, 60}};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Optimal profit is " << getMaxProfit(arr, n);

    return 0;
}