#include <bits/stdc++.h>
using namespace std;

int getMinDifference(int arr[], int n, int k) {
    sort(arr, arr + n);

    int res = arr[n - 1] - arr[0];
    int smallest = arr[0] + k;
    int largest = arr[n - 1] - k;

    for (int i = 0; i < n - 1; ++i) {
        int min_e = min(smallest, arr[i + 1] - k);
        int max_e = max(largest, arr[i] + k);

        // if negative heights not allowed
        if (min_e < 0)
            continue;

        res = min(res, max_e - min_e);
    }

    return res;
}

int main() {

    int arr[] = {1, 5, 8, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 2;

    cout << getMinDifference(arr, n, k);

    return 0;
}