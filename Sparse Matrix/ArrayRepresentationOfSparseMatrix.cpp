#include <bits/stdc++.h>
using namespace std;

int main() {
    int sparseMatrix[4][5] = {{0, 0, 3, 0, 4},
                              {0, 0, 5, 7, 0},
                              {0, 0, 0, 0, 0},
                              {0, 2, 6, 0, 0}};

    int size = 0;
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 5; ++j)
            if (sparseMatrix[i][j] != 0)
                size++;

    int compact[3][size];
    int k = 0;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 5; ++j) {
            if (sparseMatrix[i][j] != 0) {
                compact[0][k] = i;
                compact[1][k] = j;
                compact[2][k] = sparseMatrix[i][j];
                k++;
            }
        }
    }

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < size; ++j)
            cout << compact[i][j] << " ";
        cout << endl;
    }

    return 0;
}