#include <bits/stdc++.h>
using namespace std;

int kth(int start1, int arr1[], int end1, int start2, int arr2[], int end2, int k) {
    if (start1 > end1)
        return arr2[start2 + k - 1];
    if (start2 > end2)
        return arr1[start1 + k - 1];

    int mid1 = (end1 + start1) / 2;
    int mid2 = (end2 + start2) / 2;
    int kc = (mid1 - start1 + 1) + (mid2 - start2 + 1);

    if (kc <= k) {
        if (arr1[mid1] < arr2[mid2])
            return kth(mid1 + 1, arr1, end1, start2, arr2, end2, k - (mid1 - start1 + 1));
        else
            return kth(start1, arr1, end1, mid2 + 1, arr2, end2, k - (mid2 - start2 + 1));
    } else {
        if (arr1[mid1] < arr2[mid2])
            return kth(start1, arr1, end1, start2, arr2, mid2 - 1, k);
        else
            return kth(start1, arr1, mid1 - 1, start2, arr2, end2, k);
    }
}

int main() {
    int arr1[7] = {1, 10, 10, 25, 40, 54, 79};
    int arr2[11] = {15, 24, 27, 32, 33, 39, 48, 68, 82, 88, 90};

    int k = 15;
    cout << kth(0, arr1, 6, 0, arr2, 10, k);

    return 0;
}