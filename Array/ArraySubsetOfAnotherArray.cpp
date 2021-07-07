#include <bits/stdc++.h>
using namespace std;

// Time : O(n + m)
// Space : (n)
bool isSubset(int arr1[], int arr2[], int n, int m) {
    unordered_set<int> seen;

    for (int i = 0; i < n; ++i)
        seen.insert(arr1[i]);

    for (int i = 0; i < m; ++i)
        if (seen.find(arr2[i]) == seen.end())
            return false;

    return true;
}

int main() {
    int arr1[] = {11, 1, 13, 21, 3, 7};
    int arr2[] = {11, 3, 7, 1};
    int n = sizeof(arr1) / sizeof(arr1[0]);
    int m = sizeof(arr2) / sizeof(arr2[0]);

    cout << isSubset(arr1, arr2, n, m);

    return 0;
}