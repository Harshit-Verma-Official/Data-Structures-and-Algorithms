#include <bits/stdc++.h>
using namespace std;

// Time : O(n^2)
// Space : O(1)
bool findTriplet(int arr[], int n, int sum) {
    sort(arr, arr + n);

    for (int i = 0; i < n; ++i) {
        int l = i + 1;
        int r = n - 1;
        while (l < r) {
            int tempSum = arr[i] + arr[l] + arr[r];
            if (tempSum == sum)
                return true;
            else if (tempSum < sum)
                l++;
            else
                r--;
        }
    }

    return false;
}

int main() {
    int arr[] = {1, 4, 45, 6, 10, 8};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << findTriplet(arr, n, 13);

    return 0;
}