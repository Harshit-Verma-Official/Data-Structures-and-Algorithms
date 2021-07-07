#include <bits/stdc++.h>
using namespace std;

int merge(int arr[], int temp[], int left, int mid, int right) {
    int inversions = 0;
    int i = left;
    int j = mid;
    int k = left;

    while (i <= mid - 1 and j <= right) {
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else {
            temp[k++] = arr[j++];
            inversions += (mid - i);
        }
    }

    while (i <= mid - 1)
        temp[k++] = arr[i++];
    while (j <= right)
        temp[k++] = arr[j++];

    for (int i = left; i <= right; ++i)
        arr[i] = temp[i];

    return inversions;
}

int mergeSort(int arr[], int temp[], int left, int right) {
    int inversions = 0;
    if (left < right) {
        int mid = (left + right) / 2;
        inversions += mergeSort(arr, temp, left, mid);
        inversions += mergeSort(arr, temp, mid + 1, right);
        inversions += merge(arr, temp, left, mid + 1, right);
    }
    return inversions;
}
// arr[]: Input Array
// N : Size of the Array arr[]
// Function to count inversions in the array.
int inversionCount(int arr[], int n) {
    int temp[n];
    return mergeSort(arr, temp, 0, n - 1);
}

int main() {
    int arr[] = {2, 4, 1, 3, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    int inversions = inversionCount(arr, n);

    cout << "Inversion Count = " << inversions << endl;
}