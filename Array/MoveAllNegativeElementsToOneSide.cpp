#include <bits/stdc++.h>
using namespace std;

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void rearrange(int arr[], int n) {
    int i = 0;
    int j = n - 1;

    while (i < j) {
        while (arr[i] < 0)
            i++;
        while (arr[j] >= 0)
            j--;
        if (i < j)
            swap(&arr[i], &arr[j]);
    }
}

void rearrangeByPivot(int arr[], int n) {
    int boundary = -1;
    for (int i = 0; i < n; ++i) {
        if (arr[i] < 0)
            swap(&arr[i], &arr[++boundary]);
    }
}

int main() {
    int arr[] = {-12, 11, -13, -5,
                 6, -7, 5, -3, 11};
    int n = sizeof(arr) / sizeof(arr[0]);
    rearrangeByPivot(arr, n);
    printArray(arr, n);
    return 0;
}