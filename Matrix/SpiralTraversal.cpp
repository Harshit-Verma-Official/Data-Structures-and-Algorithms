#include <bits/stdc++.h>
using namespace std;

#define R 3
#define C 6

void spiralPrint(int arr[R][C], int r, int c) {
    int top = 0;
    int down = r - 1;
    int left = 0;
    int right = c - 1;
    while (top <= down and left <= right) {
        for (int i = top; i <= right; ++i)
            cout << arr[top][i] << " ";
        top++;

        for (int i = top; i <= down; ++i)
            cout << arr[i][right] << " ";
        right--;

        if (top <= down) {
            for (int i = right; i >= left; --i)
                cout << arr[down][i] << " ";
            down--;
        }

        if (left <= right) {
            for (int i = down; i >= top; --i)
                cout << arr[i][left] << " ";
            left++;
        }
    }
}

int main() {
    int arr[R][C] = {{1, 2, 3, 4, 5, 6},
                     {7, 8, 9, 10, 11, 12},
                     {13, 14, 15, 16, 17, 18}};

    // spiralPrint(arr, R, C);

    vector<int> res;
    res.push_back(10);
    res.push_back(30);
    res.push_back(3);
    res.push_back(60);
    cout << binary_search(res.begin(), res.end(), 60);

    return 0;
}