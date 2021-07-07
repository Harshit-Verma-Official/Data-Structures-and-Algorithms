#include <bits/stdc++.h>
using namespace std;

// Method 1
// Time : O(n^2)
// Space : O(1)
int smallestSubWithSum(int arr[], int n, int x) {
    int smallest_len = n + 1;

    for (int start = 0; start < n; ++start) {
        int sum = arr[start];

        if (sum > x)
            return 1;

        int j;
        for (j = start + 1; j < n; ++j) {
            sum += arr[j];
            if (sum > x and (j - start + 1) < smallest_len)
                smallest_len = j - start + 1;
        }
    }

    return smallest_len;
}

// Method 2
// Time : O(n)
// Space : O(1)
int getMinSubArrayLength(int arr[], int n, int x) {
    int min_l = n + 1;

    int i = 0;
    int j = 0;

    int sum = 0;

    while (i <= j and j < n) {
        while (sum < x and j < n)
            sum += arr[j++];
        while (sum > x and i <= j) {
            sum -= arr[i++];
            min_l = min(min_l, j - i + 1);
        }
    }

    return min_l;
}

int main() {
    int arr1[] = {1, 10, 5, 2, 7};
    int x = 9;
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int res1 = getMinSubArrayLength(arr1, n1, x);
    (res1 == n1 + 1) ? cout << "Not possible\n" : cout << res1 << endl;

    return 0;
}