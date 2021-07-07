#include <bits/stdc++.h>
using namespace std;

vector<int> findCommon(int a[], int b[], int c[], int n1, int n2, int n3) {
    vector<int> res;
    int i = 0;
    int j = 0;
    int k = 0;
    int lastDuplicate = INT_MIN;

    while (i < n1 and j < n2 and k < n3) {
        if (a[i] == b[j] and b[j] == c[k]) {
            if (a[i] != lastDuplicate)
                res.push_back(a[i]);
            i++;
            j++;
            k++;
        } else if (a[i] < b[j])
            i++;
        else if (b[j] < c[k])
            j++;
        else
            k++;
    }

    return res;
}

int main() {
    int A[] = {1, 5, 10, 20, 40, 80};
    int B[] = {6, 7, 20, 80, 100};
    int C[] = {3, 4, 15, 20, 30, 70, 80, 120};

    int n1 = sizeof(A) / sizeof(A[0]);
    int n2 = sizeof(B) / sizeof(B[0]);
    int n3 = sizeof(C) / sizeof(C[0]);

    vector<int> res = findCommon(A, B, C, n1, n2, n3);

    for (int i = 0; i < res.size(); ++i)
        cout << res[i] << " ";

    return 0;
}