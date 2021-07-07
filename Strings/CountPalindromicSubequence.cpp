#include <bits/stdc++.h>
using namespace std;

int countPalindromicSubsequence(string str) {
    int n = str.length();
    int res = 0;

    bool dp[n][n];
    memset(dp, 0, sizeof(dp));

    res = n;
    for (int i = 0; i < n; ++i)
        dp[i][i] = true;

    for (int i = 0; i < n - 1; ++i) {
        if (str[i] == str[i + 1]) {
            res++;
            dp[i][i + 1] = true;
        }
    }

    for (int k = 3; k <= n; ++k) {
        for (int i = 0; i < n - k + 1; ++i) {
            int j = i + k - 1;
            if (str[i] == str[j] and dp[i + 1][j - 1]) {
                res++;
                dp[i][j] = true;
            }
        }
    }

    return res;
}

int main() {

    string str = "aaa";

    cout << countPalindromicSubsequence(str);

    return 0;
}