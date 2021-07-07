#include <bits/stdc++.h>
using namespace std;

#define n 4

void merge(int arr1[], int arr2[], int n1, int n2, int output[]) {
    int i = 0;
    int j = 0;
    int k = 0;

    while (i < n1 and j < n2) {
        if (arr1[i] <= arr2[j])
            output[k++] = arr1[i++];
        else
            output[k++] = arr2[j++];
    }

    while (i < n1)
        output[k++] = arr1[i++];
    while (j < n2)
        output[k++] = arr2[j++];
}

void mergeArrays(int arr[][n], int i, int j, int output[]) {
    if (i == j) {
        for (int p = 0; p < n; ++p)
            output[p] = arr[i][p];
        return;
    }

    if (j - i == 1) {
        merge(arr[i], arr[j], n, n, output);
        return;
    }

    int out1[n * (((i + j) / 2) - i + 1)];
    int out2[n * (j - ((i + j) / 2))];

    mergeArrays(arr, i, (i + j) / 2, out1);
    mergeArrays(arr, (i + j) / 2 + 1, j, out2);

    merge(out1, out2, n * (((i + j) / 2) - i + 1), n * (j - ((i + j) / 2)), output);
}

int main() {
    int arr[][n] = {{2, 6, 12, 34},
                    {1, 9, 20, 1000},
                    {23, 34, 90, 2000}};
    int k = sizeof(arr) / sizeof(arr[0]);
    int output[n * k];

    mergeArrays(arr, 0, 2, output);

    for (int i = 0; i < n * k; ++i)
        cout << output[i] << " ";

    return 0;
}