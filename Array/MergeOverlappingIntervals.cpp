#include <bits/stdc++.h>
using namespace std;

struct Interval {
    int start;
    int end;
};

bool compareIntervals(Interval a, Interval b) {
    return a.start < b.start;
}

// Method 1 : Using Stack
// Time     : O(nlogn)
// Space    : O(n);
void mergeIntervals(Interval arr[], int n) {
    if (n <= 0)
        return;

    sort(arr, arr + n, compareIntervals);

    stack<Interval> stack;
    stack.push(arr[0]);

    for (int i = 1; i < n; ++i) {
        if (stack.top().end < arr[i].start)
            stack.push(arr[i]);
        else
            stack.top().end = max(stack.top().end, arr[i].end);
    }

    while (!stack.empty()) {
        cout << "[" << stack.top().start << ", " << stack.top().end << "]" << endl;
        stack.pop();
    }
}

// Method 2 : Two Pointers
// Time : O(nlogn)
// Space : O(1)
void mergeIntervalsInConstantSpace(Interval arr[], int n) {
    sort(arr, arr + n, compareIntervals);

    int index = 0;

    for (int i = 1; i < n; ++i) {
        if (arr[index].end >= arr[i].start)
            arr[index].end = max(arr[index].end, arr[i].end);
        else {
            index++;
            arr[index] = arr[i];
        }
    }

    for (int i = 0; i <= index; ++i)
        cout << "[" << arr[i].start << ", " << arr[i].end << "]" << endl;
}

int main() {

    Interval arr[] = {{1, 2}, {2, 4}, {5, 8}, {7, 10}, {11, 12}};
    int n = sizeof(arr) / sizeof(arr[0]);
    mergeIntervalsInConstantSpace(arr, n);

    return 0;
}