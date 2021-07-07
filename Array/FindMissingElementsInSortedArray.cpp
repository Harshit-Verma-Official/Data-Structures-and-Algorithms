#include <bits/stdc++.h>
using namespace std;

void printMissingElements(int arr[], int size) {
    int diff = arr[0];
    for (int i = 0; i < size; ++i) {
        if (arr[i] - i != diff) {
            while (diff < arr[i] - i) {
                cout << i + diff << " ";
                diff++;
            }
        }
    }
}

int main() {
    int arr[] = {1, 2, 4, 5, 6, 9, 10};
    int size = sizeof(arr) / sizeof(arr[0]);

    printMissingElements(arr, size);

    return 0;
}