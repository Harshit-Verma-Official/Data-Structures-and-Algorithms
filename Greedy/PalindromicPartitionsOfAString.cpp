#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool isPalindrome(string &s, int i, int j) {
        while (i < j)
            if (s[i++] != s[j--])
                return false;
        return true;
    }
    void solve(string &s, int index, vector<string> &path, vector<vector<string>> &res) {
        if (index == s.size()) {
            res.push_back(path);
            return;
        }
        
        for (int i = index; i < s.size(); ++i) {
            if (isPalindrome(s, index, i)) {
                path.push_back(s.substr(index, i - index + 1));
                solve(s, i + 1, path, res);
                path.pop_back();
            }
        }
    }
    vector<vector<string>> allPalindromicPerms(string s) {
        vector<vector<string>> res;
        vector<string> path;
        
        solve(s, 0, path, res);
        
        return res;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        
        cin>>S;

        Solution ob;
        vector<vector<string>> ptr = ob.allPalindromicPerms(S);
        
        for(int i=0; i<ptr.size(); i++)
        {
            for(int j=0; j<ptr[i].size(); j++)
            {
                cout<<ptr[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}

// Time Complexity: O(N*2N)
// Auxiliary Space: O(N2), where N is the length of the String

// Test case : 
// 1
// abb