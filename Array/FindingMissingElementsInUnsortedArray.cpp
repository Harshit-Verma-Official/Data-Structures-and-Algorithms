#include <bits/stdc++.h>
using namespace std;

void printMissingElements(int arr[], int size) {
    int max = arr[0];
    int min = arr[0];
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
        if (seen[i] == 0)
            cout << i << " ";
}

int main() {
    int arr[] = {9, 5, 1, 7, 5, 3};
    int size = sizeof(arr) / sizeof(arr[0]);

    printMissingElements(arr, size);

    return 0;
}