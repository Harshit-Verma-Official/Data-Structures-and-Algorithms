#include <bits/stdc++.h>
using namespace std;

void getMinMax(int arr[], int size) {
    int min;
    int max;

    int i = 0;
    if (size % 2 == 0) {
        if (arr[0] < arr[1]) {
            min = arr[0];
            max = arr[1];
        } else {
            min = arr[1];
            max = arr[0];
        }
        i = 2;
    } else {
        min = arr[0];
        max = arr[0];
        i = 1;
    }

    while (i < size - 1) {
        if (arr[i] > arr[i + 1]) {
            if (arr[i] > max)
                max = arr[i];
            if (arr[i + 1] < min)
                min = arr[i + 1];
        } else {
            if (arr[i + 1] > max)
                max = arr[i + 1];
            if (arr[i] < min)
                min = arr[i];
        }
        i += 2;
    }

    cout << "Min : " << min << endl;
    cout << "Max : " << max << endl;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 9, 10};
    int size = sizeof(arr) / sizeof(arr[0]);

    getMinMax(arr, size);

    return 0;
}