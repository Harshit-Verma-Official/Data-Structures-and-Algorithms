#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int solve(string &s, string &t, int i, int j, vector<vector<int>> &dp) {
        if (i == 0)
            return j;
        if (j == 0)
            return i;
        
        if (dp[i][j] != -1)
            return dp[i][j];
        
        if (s[i] == s[j])
            return dp[i][j] = dp[i - 1][j - 1];
        
        int insert = solve(s, t, i, j - 1, dp);
        int rem = solve(s, t, i - 1, j, dp);
        int replace = solve(s, t, i - 1, j - 1, dp);
        
        return dp[i][j] = min(insert, rem, replace);
    }
    
    int editDistance(string s, string t) {
        int m = s.length();
        int n = t.length();
        // vector<vector<int>> dp(m, vector<int>(n, -1));
        
        return solve(s, t, m - 1, n - 1, dp);
    }
};

void eraseSubStr(std::string & mainStr, const std::string & toErase)
{
    // Search for the substring in string
    size_t pos = mainStr.find(toErase);

    if (pos != std::string::npos)
    {
        // If found then erase it from string
        mainStr.erase(pos, toErase.length());
    }
}

int main() {
	string str = "apple5abc11d";
    int n = str.length();

    int i = 1;
    while (true) {
        if (n <= 10 * i) {
            n--;
            break;
        }
        i++;
    }

    string len = to_string(n);


    eraseSubStr(str, len);

    cout << str;

}