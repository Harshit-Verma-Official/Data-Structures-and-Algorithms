#include <bits/stdc++.h>
using namespace std;

bool search(int mat[4][4], int r, int c, int target) {
    int i = 0;
    int j = c - 1;

    while (i < r and j >= 0) {
        if (mat[i][j] == target)
            return true;
        else if (target > mat[i][j])
            i++;
        else
            j--;
    }

    return false;
}

int main() {
    int mat[4][4] = {{10, 20, 30, 40},
                     {15, 25, 35, 45},
                     {27, 29, 37, 48},
                     {32, 33, 39, 50}};

    cout << search(mat, 4, 4, 29);

    return 0;
}