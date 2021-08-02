#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:

    int editDistanceRecursive(string &s, string &t, int i, int j, vector<vector<int>> &dp) {
        if (i == -1)
            return j + 1;
        if (j == -1)
            return i + 1;
        
        if (dp[i][j] != -1)
            return dp[i][j];
        
        if (s[i] == t[j])
            return dp[i][j] = solve(s, t, i - 1, j - 1, dp);
        
        int ins = solve(s, t, i, j - 1, dp);
        int rem = solve(s, t, i - 1, j, dp);
        int rep = solve(s, t, i - 1, j - 1, dp);
        
        return dp[i][j] = min(ins, min(rem, rep)) + 1;
    }

    int editDistance(string s, string t) {
        int m = s.length();
        int n = t.length();
        
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        
        for (int i = 0; i <= m; ++i) {
            for (int j = 0; j <= n; ++j) {
                if (i == 0)
                    dp[i][j] = j;
                else if (j == 0)
                    dp[i][j] = i;
                else if (s[i - 1] == t[j - 1])
                    dp[i][j] = dp[i - 1][j - 1];
                else
                    dp[i][j] = 1 + min(dp[i - 1][j], min(dp[i - 1][j - 1], dp[i][j - 1]));
            }
        }
        
        return dp[m][n];
    }
};

int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}

// Time Complexity: O(|s|*|t|)
// Space Complexity: O(|s|*|t|)

// Test Case : 
// 1
// horse ros