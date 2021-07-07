#include <bits/stdc++.h>
using namespace std;

// Time : O(n + m)
// Space : O(1)
int findRow(int mat[4][4], int n, int m) {
    int i = 0;
    int j = m - 1;

    int count = 0;
    int index = -1;

    while (i < n and j >= 0) {
        if (mat[i][j] > 0) {
            j--;
            count++;
            if (count > 0)
                index = i;
        } else
            i++;
    }

    return index;
}

int main() {
    int mat[4][4] = {{0, 1, 1, 1},
                     {0, 0, 1, 1},
                     {1, 1, 1, 1},
                     {0, 0, 0, 0}};

    cout << findRow(mat, 4, 4);

    return 0;
}