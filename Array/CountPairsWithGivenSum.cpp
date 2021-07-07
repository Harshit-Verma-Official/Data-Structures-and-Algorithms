#include <bits/stdc++.h>
using namespace std;

int getPairsCount(int arr[], int n, int k) {
    unordered_map<int, int> seen;
    int twiceCount = 0;
    for (int i = 0; i < n; ++i)
        seen[arr[i]]++;
    for (int i = 0; i < n; ++i) {
        twiceCount += seen[k - arr[i]];
        if (k - arr[i] == arr[i])
            twiceCount--;
    }
    return twiceCount / 2;
}

int main() {

    int arr[] = {1, 1, 1, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << getPairsCount(arr, n, 2);

    return 0;
}