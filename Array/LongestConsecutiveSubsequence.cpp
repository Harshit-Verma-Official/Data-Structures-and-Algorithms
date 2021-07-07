#include <bits/stdc++.h>
using namespace std;

// Method 1
// Time : O(nlogn)
// Space : O(1)
int findLongestConsecutiveSubsequence(int arr[], int n) {
    sort(arr, arr + n);

    int max_v = 1;
    int cur = arr[0];
    int temp_v = 1;
    for (int i = 1; i < n; ++i) {
        if (arr[i] == arr[i - 1])
            continue;
        else if (arr[i] == cur + 1) {
            cur = arr[i];
            temp_v++;
        } else {
            max_v = max(max_v, temp_v);
            temp_v = 1;
        }
    }

    return max_v;
}

// Method 2 : Hashing
// Time : O(n)
// Space : O(n)
int findLongestConsecutiveSubsequenceByHashing(int arr[], int n) {
    unordered_set<int> set;
    for (int i = 0; i < n; ++i)
        set.insert(arr[i]);

    int longest = 1;
    for (int i = 0; i < n; ++i) {
        if (set.find(arr[i] - 1) == set.end()) {
            int temp_l = 1;
            int cur = arr[i];
            while (set.find(++cur) != set.end())
                temp_l++;
            longest = max(longest, temp_l);
        }
    }

    return longest;
}

int main() {
    int arr[] = {1, 9, 3, 10, 4, 20, 2};
    int n = sizeof arr / sizeof arr[0];
    cout << "Length of the Longest contiguous subsequence is " << findLongestConsecutiveSubsequenceByHashing(arr, n);

    return 0;
}