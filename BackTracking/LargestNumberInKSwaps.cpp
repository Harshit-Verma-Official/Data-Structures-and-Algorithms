#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    void solve(string str, int k, int cur, string &maxv) {
        if (k == 0)
            return;
        
        int n = str.length();
        
        char maxc = str[cur];
        
        for (int i = cur + 1; i < n; ++i)
            if (str[i] > maxc)
                maxc = str[i];
        
        if (maxc != str[cur])
            k--;
        
        for (int i = cur; i < n; ++i) {
            if (str[i] == maxc) {
                swap(str[cur], str[i]);
                
                if (str.compare(maxv) > 0)
                    maxv = str;
                
                solve(str, k, cur + 1, maxv);
                
                swap(str[cur], str[i]);
            }
        }
    }
    string findMaximumNum(string str, int k) {
        string maxv = str;
        solve(str, k, 0, maxv);
        return maxv;
    }
};

int main()
{
    int t, k;
    string str;

    cin >> t;
    while (t--)
    {
        cin >> k >> str;
        Solution ob;
        cout<< ob.findMaximumNum(str, k) << endl;
    }
    return 0;
}

// Time Complexity: O(n^k). 
// For every recursive call n recursive calls is generated until the value of k is 0. So total recursive calls are O((n)^k).
// Space Complexity: O(n). 
// The space required to store the output string.

// Test case : 
// 1
// 4
// 1234567