#include <bits/stdc++.h>
using namespace std;

void findPair(int arr[], int size, int sum) {
    int i = 0;
    int j = size - 1;
    while (i < j) {
        if (arr[i] + arr[j] == sum) {
            cout << "(" << arr[i] << ", " << arr[j] << ")" << endl;
            i++;
            j--;
        } else if (arr[i] + arr[i] < sum)
            i++;
        else
            j--;
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 9, 10};
    int size = sizeof(arr) / sizeof(arr[0]);

    findPair(arr, size, 12);

    return 0;
}