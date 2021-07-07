#include <bits/stdc++.h>
using namespace std;

// Method 1
// Time : O(n^2)
// Space : O(1)
int trapByMethod1(int height[], int n) {
    if (n < 2)
        return 0;

    int res = 0;

    for (int i = 1; i < n - 1; ++i) {
        int max_l = height[i];
        int max_r = height[i];

        for (int l = 0; l < i; ++l)
            max_l = max(max_l, height[l]);
        for (int r = i + 1; r < n; ++r)
            max_r = max(max_r, height[r]);

        res += (min(max_l, max_r) - height[i]);
    }

    return res;
}

// Method 2
// Time : O(n)
// Space : O(n)
int trapByMethod2(int height[], int n) {
    if (n < 2)
        return 0;

    int max_h_to_left[n];
    int max_h_from_right[n];

    max_h_to_left[0] = height[0];
    max_h_from_right[n - 1] = height[n - 1];

    for (int i = 1, j = n - 2; i < n; ++i, --j) {
        max_h_to_left[i] = max(max_h_to_left[i - 1], height[i]);
        max_h_from_right[j] = max(max_h_from_right[j + 1], height[j]);
    }

    int res = 0;

    for (int i = 1; i < n - 1; ++i)
        res += (min(max_h_to_left[i], max_h_from_right[i]) - height[i]);

    return res;
}

// Method 3
// Time : O(n)
// Space : O(1)
int trapByMethod3(int height[], int n) {
    if (n < 2)
        return 0;

    int left = 0;
    int right = n - 1;

    int max_l = 0;
    int max_r = 0;

    int res = 0;

    while (left <= right) {
        if (height[left] <= height[right]) {
            if (height[left] >= max_l)
                max_l = height[left];
            else
                res += (max_l - height[left]);
            left++;
        } else {
            if (height[right] >= max_r)
                max_r = height[right];
            else
                res += (max_r - height[right]);
            right--;
        }
    }

    return res;
}

int main() {

    int arr[] = {3, 0, 0, 2, 0, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << trapByMethod3(arr, n);

    return 0;
}