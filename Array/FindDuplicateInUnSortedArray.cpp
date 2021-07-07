#include <bits/stdc++.h>
using namespace std;

void findDuplicates(int arr[], int size) {
    int min = arr[0];
    int max = arr[0];
    for (int i = 0; i < size; ++i) {
        if (arr[i] > max)
            max = arr[i];
        if (arr[i] < min)
            min = arr[i];
    }
    int seen[max + 1] = {0};
    for (int i = 0; i < size; ++i)
        seen[arr[i]]++;
    for (int i = min; i <= max; ++i)
        if (seen[i] > 1)
            cout << i << " is appearing " << seen[i] << " times.\n";
}

int main() {
    int arr[] = {9, 8, 7, 8, 5, 8, 6, 3, 3, 1, 4, 6, 9};
    int size = sizeof(arr) / sizeof(arr[0]);

    findDuplicates(arr, size);

    return 0;
}