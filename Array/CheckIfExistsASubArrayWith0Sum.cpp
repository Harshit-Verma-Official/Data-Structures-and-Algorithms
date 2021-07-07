#include <bits/stdc++.h>
using namespace std;

// Time : O(n)
// Space : O(n)
bool subArrayExists(int arr[], int n) {
    unordered_set<int> prefixSums;
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        if (arr[i] == 0)
            return true;

        sum += arr[i];
        if (sum == 0 or prefixSums.find(sum) != prefixSums.end())
            return true;

        prefixSums.insert(sum);
    }

    return false;
}

int main() {

    int arr[] = {4, 2, -3, 1, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << subArrayExists(arr, n);

    return 0;
}