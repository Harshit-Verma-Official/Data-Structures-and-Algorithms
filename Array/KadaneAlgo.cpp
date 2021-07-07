#include <bits/stdc++.h>
using namespace std;

// Method 1 : Naive
// O(n^3)
int maxSubArraySumNaive(int arr[], int n) {
    int max = INT_MIN;
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            int tempSum = 0;
            for (int k = i; k < j; ++k)
                tempSum += arr[k];
            if (tempSum > max)
                max = tempSum;
        }
    }
    return max;
}

// Method 2 : Prefix Sum
// O(n^2)
int maxSubArraySumByPrefixSum(int arr[], int n) {
    int prefixSums[n + 1];
    prefixSums[0] = 0;
    for (int i = 0; i < n; ++i)
        prefixSums[i + 1] = prefixSums[i] + arr[i];

    int max = INT_MIN;
    for (int i = 1; i <= n; ++i) {
        for (int j = i; j <= n; ++j) {
            int tempSum = prefixSums[j] - prefixSums[i - 1];
            if (tempSum > max)
                max = tempSum;
        }
    }

    return max;
}

// Method 3 (Efficient) : Kadane's Algorithm
// O(n)
int maxSubArraySum(int arr[], int n) {
    int max = INT_MIN;
    int max_th = 0;
    int start = 0, end = 0, s = 0;
    for (int i = 0; i < n; ++i) {
        max_th += arr[i];
        if (max_th > max) {
            max = max_th;
            start = s;
            end = i;
        }
        if (max_th < 0) {
            max_th = 0;
            s = i + 1;
        }
    }
    for (int i = start; i <= end; ++i)
        cout << arr[i] << " ";
    return max;
}

int main() {

    int a[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int n = sizeof(a) / sizeof(a[0]);
    int max_sum = maxSubArraySum(a, n);
    cout << "Maximum contiguous sum is " << max_sum;

    return 0;
}