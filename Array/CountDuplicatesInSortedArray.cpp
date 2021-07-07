#include <bits/stdc++.h>
using namespace std;

void countDuplicates(int arr[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        if (arr[i] == arr[i + 1]) {
            int j = i + 1;
            while (arr[j] == arr[i])
                j++;
            cout << arr[i] << " is appeared " << (j - i) << " times.\n";
            i = j - 1;
        }
    }
}

void findDuplicates(int arr[], int size) {
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
    for (int i = 0; i <= max; ++i)
        if (seen[i] > 1)
            cout << i << " is appeared " << seen[i] << " times.\n";
}

int main() {
    int arr[] = {1, 2, 3, 3, 4, 5, 6, 6, 6, 7, 7};
    int size = sizeof(arr) / sizeof(arr[0]);

    findDuplicates(arr, size);

    return 0;
}