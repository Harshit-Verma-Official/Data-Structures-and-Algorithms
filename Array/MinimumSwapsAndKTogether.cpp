#include <bits/stdc++.h>
using namespace std;

// Time : O(n)
// Space : O(1)
int minSwap(int arr[], int n, int k) {
    int window_size = 0;
    for (int i = 0; i < n; ++i)
        if (arr[i] <= k)
            window_size++;

    int bad = 0;
    for (int i = 0; i < window_size; ++i)
        if (arr[i] > k)
            bad++;

    int ans = bad;
    for (int i = 0, j = window_size; j < n; ++i, ++j) {
        if (arr[i] > k)
            bad--;
        if (arr[j] > k)
            bad++;
        ans = min(ans, bad);
    }

    return ans;
}

int main() {

    int arr[] = {2, 1, 5, 6, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;
    cout << minSwap(arr, n, k) << "\n";

    return 0;
}