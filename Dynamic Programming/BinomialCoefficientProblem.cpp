#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int nCr(int n, int r) {
        if (r > n)
            return 0;
        
        if (n - r < r)
            r = n - r;
        
        int mod = 1000000007;
        int dp[r + 1] = { 0 };
        dp[0] = 1;
        
        for (int i = 1; i <= n; ++i)
            for (int j = min(i, r); j > 0; --j)
                dp[j] = (dp[j] + dp[j - 1]) % mod;
        
        return dp[r];
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, r;
        cin>>n>>r;
        
        Solution ob;
        cout<<ob.nCr(n, r)<<endl;
    }
    return 0;
}

// Time Complexity: O(n*r)
// Auxiliary Space: O(r)

// Test Case : 
// 1
// 3 2