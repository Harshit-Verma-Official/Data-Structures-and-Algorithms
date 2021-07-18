#include <bits/stdc++.h>
using namespace std;

int getMaxChar(vector<int> &count) {
    int max = 0;
    char ch;
    for (int i = 0; i < 26; ++i) {
        if (count[i] > max) {
            max = count[i];
            ch = i + 'a';
        }
    }
    return ch;
}

bool solve(string s) {
    int n = s.size();
    
    if (!n)
        return true;
    
    vector<int> count(26, 0);
    for (auto ch : s)
        count[ch - 'a']++;
    
    int ch_max = getMaxChar(count);
    int maxCount = count[ch_max - 'a'];
    
    return maxCount > (n + 1) / 2 ? false : true;;
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        string s;
        cin >> s;
        cout << solve(s) << endl;
    }
    
	return 0;
}

// Test case :
// 1
// bbbbb