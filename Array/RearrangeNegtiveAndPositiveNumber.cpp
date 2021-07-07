#include <bits/stdc++.h>
using namespace std;

void rotateRight(int arr[], int from, int to) {
    int item = arr[to];
    for (int i = to; i > from; --i)
        arr[i] = arr[i - 1];
    arr[from] = item;
}

bool isEven(int item) {
    return item % 2 == 0;
}

// Time : O(n)
// Space : O(n)
void rearrangeInLinearTime(int arr[], int n) {
    vector<int> pv, nv;
    for (int i = 0; i < n; ++i) {
        if (arr[i] < 0)
            nv.push_back(arr[i]);
        else
            pv.push_back(arr[i]);
    }
    int i = 0;
    int j = 0;
    int k = 0;
    while (i < pv.size() and j < nv.size()) {
        arr[k++] = pv[i++];
        arr[k++] = nv[j++];
    }

    while (i < pv.size())
        arr[k++] = pv[i++];
    while (j < nv.size())
        arr[k++] = nv[j++];
}

// Time : O(n^2)
// Space : O(1)
void rearrangeNegativePositive(int arr[], int n) {
    int outOfPlace = -1;
    for (int i = 0; i < n; ++i) {
        if (outOfPlace >= 0) {
            if ((arr[outOfPlace] < 0 and arr[i] >= 0) or (arr[outOfPlace] >= 0 and arr[i] < 0)) {
                rotateRight(arr, outOfPlace, i);

                if (i - outOfPlace >= 2)
                    outOfPlace += 2;
                else
                    outOfPlace = -1;
            }
        }

        if (outOfPlace == -1)
            if ((isEven(i) and arr[i] < 0) or (!isEven(i) and arr[i] >= 0))
                outOfPlace = i;
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
}

int main() {

    int arr[] = {-5, -2, 5, 2, 4, 7, 1, 8, 0, -8};
    int n = sizeof(arr) / sizeof(arr[0]);

    rearrangeNegativePositive(arr, n);
    printArray(arr, n);

    return 0;
}