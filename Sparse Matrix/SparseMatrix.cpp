#include <bits/stdc++.h>
using namespace std;

class Element {
public:
    int r;
    int c;
    int e;
    Element() {}
    Element(int r, int c, int e) {
        this->r = r;
        this->c = c;
        this->e = e;
    }
};

class SparseMatix {
public:
    int rows;
    int cols;
    int count;
    int size;
    Element *bucket;
    SparseMatix(int rows, int cols, int size) {
        this->rows = rows;
        this->cols = cols;
        this->size = size;
        count = 0;
        bucket = new Element[size];
    }

    void insert(int r, int c, int e) {
        bucket[count].r = r;
        bucket[count].c = c;
        bucket[count++].e = e;
    }

    void printSparseMatrix() {
        int k = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; ++j) {
                if (i == bucket[k].r and j == bucket[k].c)
                    cout << bucket[k++].e << " ";
                else
                    cout << "0 ";
            }
            cout << endl;
        }
    }

    SparseMatix *addSparseMatrix(SparseMatix *matrix) {
        if (rows != matrix->rows or cols != matrix->cols)
            return nullptr;

        SparseMatix *res = new SparseMatix(rows, cols, size + matrix->size);
        int i = 0;
        int j = 0;

        while (i < size and j < matrix->size) {
            if (bucket[i].r < matrix->bucket[j].r) {
                res->insert(bucket[i].r, bucket[i].c, bucket[i].e);
                i++;
            } else if (bucket[i].r > matrix->bucket[j].r) {
                res->insert(matrix->bucket[j].r, matrix->bucket[j].c, matrix->bucket[j].e);
                j++;
            } else {
                if (bucket[i].c > matrix->bucket[j].c) {
                    res->insert(bucket[i].r, bucket[i].c, bucket[i].e);
                    i++;
                } else if (bucket[i].c < matrix->bucket[j].c) {
                    res->insert(matrix->bucket[j].r, matrix->bucket[j].c, matrix->bucket[j].e);
                    j++;
                } else {
                    res->insert(bucket[i].r, bucket[i].c, bucket[i].e + matrix->bucket[j].e);
                    i++;
                    j++;
                }
            }
        }

        return res;
    }
};

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

    SparseMatix compact(4, 5, size);
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 5; ++j)
            if (sparseMatrix[i][j] != 0)
                compact.insert(i, j, sparseMatrix[i][j]);

    int sparseMatrix2[4][5] = {{0, 0, 3, 0, 4},
                               {0, 0, 5, 7, 0},
                               {0, 0, 0, 0, 0},
                               {0, 2, 6, 0, 0}};

    int size2 = 0;
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 5; ++j)
            if (sparseMatrix2[i][j] != 0)
                size2++;

    SparseMatix compact2(4, 5, size2);
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 5; ++j)
            if (sparseMatrix2[i][j] != 0)
                compact2.insert(i, j, sparseMatrix2[i][j]);

    SparseMatix *res = compact.addSparseMatrix(&compact2);
    res->printSparseMatrix();

    return 0;
}