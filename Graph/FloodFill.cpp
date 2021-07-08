#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solve(vector<vector<int>> &image, int m, int n, int sr, int sc, int newColor, int sourceColor) {
        if (sr < 0 or sr >= m or sc < 0 or sc >= n)
            return;
        
        if (image[sr][sc] != sourceColor)
            return;
        
        image[sr][sc] = newColor;
        
        solve(image, m, n, sr - 1, sc, newColor, sourceColor);
        solve(image, m, n, sr + 1, sc, newColor, sourceColor);
        solve(image, m, n, sr, sc - 1, newColor, sourceColor);
        solve(image, m, n, sr, sc + 1, newColor, sourceColor);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if (newColor == image[sr][sc])
            return image;
        
        int m = image.size();
        int n = image[0].size();
        int sourceColor = image[sr][sc];
        
        solve(image, m, n, sr, sc, newColor, sourceColor);
        
        return image;
    }
};

int main() {
    vector<vector<int>> image;

    int r;
    int c;
    int sr;
    int sc;
    int newColor;

    cin >> r >> c >> sr >> sc >> newColor;

    for (int i = 0; i < r; ++i) {
        vector<int> temp;
        int var;
        for (int j = 0; j < c; ++j) {
            cin >> var;
            temp.push_back(var);
        }
        image.push_back(temp);
    }

    Solution solve;
    solve.floodFill(image, sr, sc, newColor);

    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j)
            cout << image[i][j] << " ";
        cout << endl;
    }

    return 0;
}

// Time Complexity : O(m * n)
// Space Complexity : O(1)