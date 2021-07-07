#include <bits/stdc++.h>
using namespace std;

// O(m + n)
void printDistinctUnion(int arr1[], int arr2[], int m, int n) {
    int i = 0, j = 0;
    while (i < m && j < n) {
        if (arr1[i] < arr2[j])
            cout << arr1[i++] << " ";
        else if (arr1[i] > arr2[j])
            cout << arr2[j++] << " ";
        else {
            cout << arr1[i++] << " ";
            j++;
        }
    }
    while (i < m)
        cout << arr1[i++] << " ";
    while (j < n)
        cout << arr2[j++] << " ";
}

void printUnionHandlingDuplicates(int arr1[], int arr2[], int m, int n) {
    int max = arr1[m - 1] > arr2[n - 1] ? arr1[m - 1] : arr2[n - 1];
    int seen[max + 1] = {0};

    cout << arr1[0] << " ";

    seen[arr1[0]]++;

    for (int i = 1; i < m; ++i) {
        if (arr1[i] != arr1[i - 1]) {
            cout << arr1[i] << " ";
            seen[arr1[i]]++;
        }
    }

    for (int i = 0; i < n; ++i) {
        if (seen[arr2[i]] == 0) {
            cout << arr2[i] << " ";
            seen[arr2[i]]++;
        }
    }
}

int main() {

    int arr1[] = {1, 2, 2, 2, 3};
    int arr2[] = {2, 3, 4, 5};

    int m = sizeof(arr1) / sizeof(arr1[0]);
    int n = sizeof(arr2) / sizeof(arr2[0]);

    printUnionHandlingDuplicates(arr1, arr2, m, n);

    return 0;
}