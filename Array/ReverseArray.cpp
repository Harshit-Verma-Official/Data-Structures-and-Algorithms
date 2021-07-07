#include <bits/stdc++.h>
using namespace std;

void display(int arr[], int n) {
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << endl;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void reverse(int arr[], int n) {
    int i = 0;
    int j = n - 1;
    while (i < j)
        swap(&arr[i++], &arr[j--]);
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    display(arr, n);
    reverse(arr, n);
    display(arr, n);

    return 0;
}