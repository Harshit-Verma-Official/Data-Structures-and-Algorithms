#include <bits/stdc++.h>
using namespace std;

// Time : O(n)
// Space : O(1)
void nextPermutation(int arr[], int n) {
    int idx = -1;

    for (int i = n - 1; i > 0; --i) {
        if (arr[i] > arr[i - 1]) {
            idx = i;
            break;
        }
    }

    if (idx == -1)
        reverse(arr, arr + n);
    else {
        int prev = idx;
        for (int i = idx + 1; i < n; ++i)
            if (arr[i] > arr[idx - 1] and arr[i] <= arr[prev])
                prev = i;
        swap(arr[idx - 1], arr[prev]);
        sort(arr + idx, arr + n);
    }
}

int main() {
    int arr[] = {1, 2, 3, 6, 5, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    nextPermutation(arr, n);

    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";

    return 0;
}