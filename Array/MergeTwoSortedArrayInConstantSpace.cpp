#include <bits/stdc++.h>
using namespace std;

// Method 1 () : three pointers
// O((m + n)log(m + n))
void merge(int arr1[], int arr2[], int n, int m) {
    int i = n - 1, j = 0;
    while (i >= 0 and j < m) {
        if (arr1[i] > arr2[j]) {
            swap(arr1[i], arr2[j]);
            i--, j++;
        } else
            break;
    }
    sort(arr1, arr1 + n);
    sort(arr2, arr2 + m);
}

void insertAtCorrectionPosition(int arr[], int n) {
    int first = arr[0];
    int i;
    for (i = 1; i < n and arr[i] < first; ++i)
        arr[i - 1] = arr[i];
    arr[i - 1] = first;
}

// Method 2 : insertion sort technique
// O(n * m) : n for iterating and m for linear sorting
void mergeByInsertionMethod(int arr1[], int arr2[], int n, int m) {
    for (int i = 0; i < n; ++i) {
        if (arr1[i] > arr2[0]) {
            swap(arr1[i], arr2[0]);
            insertAtCorrectionPosition(arr2, m);
        }
    }
}

int nextGap(int gap) {
    if (gap <= 1)
        return 0;
    return (gap / 2) + (gap % 2);
}

// Method 3 (Efficient) : Gap Method
// O((m + n)log(m + n))
void mergeUsingGap(int arr1[], int arr2[], int n, int m) {
    int i;
    int j;
    int gap = n + m;

    for (gap = nextGap(gap); gap > 0; gap = nextGap(gap)) {
        // Comparing elements in first array
        for (i = 0; i + gap < n; ++i)
            if (arr1[i] > arr1[i + gap])
                swap(arr1[i], arr1[i + gap]);

        // Comparing elements in both arrays
        for (j = gap > n ? gap - n : 0; i < n and j < m; ++i, ++j)
            if (arr1[i] > arr2[j])
                swap(arr1[i], arr2[j]);

        // Comparing elements in second array
        if (j < m)
            for (j = 0; j + gap < m; ++j)
                if (arr2[j] > arr2[j + gap])
                    swap(arr2[j], arr2[j + gap]);
    }
}

int main() {

    int ar1[] = {1, 5, 9, 10, 10, 15, 15, 20};
    int ar2[] = {2, 3, 8, 13};
    int m = sizeof(ar1) / sizeof(ar1[0]);
    int n = sizeof(ar2) / sizeof(ar2[0]);
    mergeUsingGap(ar1, ar2, m, n);

    cout << "After Merging \nFirst Array: ";
    for (int i = 0; i < m; i++)
        cout << ar1[i] << " ";
    cout << "\nSecond Array: ";
    for (int i = 0; i < n; i++)
        cout << ar2[i] << " ";

    return 0;
}