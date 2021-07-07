#include <bits/stdc++.h>
using namespace std;

// Time : O(n)
// Space : O(1)
int threeWayPartition(int arr[], int n, int a, int b) {
    int start = 0;
    int end = n - 1;

    for (int i = 0; i < end; ++i) {
        if (arr[i] < a)
            swap(arr[i], arr[start++]);
        else if (arr[i] > b)
            swap(arr[i--], arr[end--]);
    }
}

int main() {
    int arr[] = {1, 14, 5, 20, 4, 2, 54, 20, 87, 98, 3, 1, 32};
    int n = sizeof(arr) / sizeof(arr[0]);

    threeWayPartition(arr, n, 10, 20);

    cout << "Modified array \n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}