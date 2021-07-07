#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    void solve(int i, int j, string ans, vector<vector<int>> &m, int n, vector<vector<bool>> &vis, vector<string> &res) {
        if (i < 0 or j < 0 or i >= n or j >= n)
            return;
        if (m[i][j] == 0 or vis[i][j])
            return;
        if (i == n - 1 and j == n - 1)
            res.push_back(ans);

        vis[i][j] = true;

        solve(i - 1, j, ans + "U", m, n, vis, res);
        solve(i + 1, j, ans + "D", m, n, vis, res);
        solve(i, j - 1, ans + "L", m, n, vis, res);
        solve(i, j + 1, ans + "R", m, n, vis, res);

        vis[i][j] = false;
    }

    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> res;
        vector<vector<bool>> vis(n, vector<bool>(n));

        solve(0, 0, "", m, n, vis, res);

        sort(res.begin(), res.end());

        return res;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends

// Input Format:

// Custom input consists of 2 lines.
// First line contains an integer N.
// Next line contains N * N space-separated integers (0 or 1) denoting the matrix in row major order.
// 1
// 4
// 1 0 0 0 1 1 0 1 1 1 0 0 0 1 1 1

// Time Complexity : O((N2)4)
// Auxiliary Space : O(L *X), L = length of the path, X = number of paths.