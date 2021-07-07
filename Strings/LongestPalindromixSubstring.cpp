#include <bits/stdc++.h>
using namespace std;

void printSubStr(
    string str, int low, int high) {
    for (int i = low; i <= high; ++i)
        cout << str[i];
}

string longestPalindrome(string s) {
    int n = s.length();

    bool table[n][n];
    memset(table, 0, sizeof(table));

    int max_l = 1;
    int start = 0;

    for (int i = 0; i < n; ++i)
        table[i][i] = true;

    for (int i = 0; i < n - 1; ++i) {
        if (s[i] == s[i + 1]) {
            table[i][i + 1] = true;
            max_l = 2;
            start = i;
        }
    }

    for (int k = 3; k <= n; ++k) {
        for (int i = 0; i < n - k + 1; ++i) {
            int j = i + k - 1;
            if (s[i] == s[j] and table[i + 1][j - 1]) {
                table[i][j] = true;
                if (k > max_l) {
                    max_l = k;
                    start = i;
                }
            }
        }
    }

    printSubStr(s, start, start + max_l - 1);
}

int main() {

    string str = "kjqlrzzfmlvyoshiktodnsjjp";

    longestPalindrome(str);

    return 0;
}