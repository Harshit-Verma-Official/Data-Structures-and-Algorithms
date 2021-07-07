#include <bits/stdc++.h>
using namespace std;

// Method 1
// Time : O(m + n)
// Space : O(1)
double getMedian(int arr1[], int arr2[], int n1, int n2) {
    int i = 0;
    int j = 0;
    if ((n1 + n2) % 2 == 1) {
        int m;
        for (int count = 0; count <= (n1 + n2) / 2; ++count) {
            if (i < n1 and j < n2)
                m = arr1[i] < arr2[j] ? arr1[i++] : arr2[j++];
            else if (i < n1)
                m = arr1[i++];
            else
                m = arr2[j++];
        }
        return m;
    } else {
        int m1;
        int m2;
        for (int count = 0; count <= (n1 + n2) / 2; ++count) {
            m2 = m1;
            if (i < n1 and j < n2)
                m1 = arr1[i] < arr2[j] ? arr1[i++] : arr2[j++];
            else if (i < n1)
                m1 = arr1[i++];
            else
                m1 = arr2[j++];
        }
        return ((double)(m1 + m2) / 2);
    }
}

int main() {
    int ar1[] = {1, 2};
    int ar2[] = {3, 4};

    int n1 = sizeof(ar1) / sizeof(ar1[0]);
    int n2 = sizeof(ar2) / sizeof(ar2[0]);
    cout << getMedian(ar1, ar2, n1, n2);
    return 0;
}