#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
    int solve(int n, int x, int y, int z, vector<int> &dp) {
        if (n == 0)
            return 0;
        
        if (dp[n] != -1)
            return dp[n];
        
        int op1;
        int op2;
        int op3;
        
        op1 = op2 = op3 = INT_MIN;
        
        if (n >= x)
            op1 = solve(n - x, x, y, z, dp);
        if (n >= y)
            op2 = solve(n - y, x, y, z, dp);
        if (n >= z)
            op3 = solve(n - z, x, y, z, dp);
        
        return dp[n] =  1 + max(op1, max(op2, op3));
    }
    
    int maximizeTheCuts(int n, int x, int y, int z) {
        vector<int> dp(n + 1, -1);
        
        int ans = solve(n, x, y, z, dp);
        
        return ans < 0 ? 0 : ans;
    }
};

int main() {
    //taking testcases
    int t;
    cin >> t;

    while(t--) {
        //taking length of line segment
        int n;
        cin >> n;
        
        //taking types of segments
        int x,y,z;
        cin>>x>>y>>z;

        Solution obj;

        //calling function maximizeTheCuts()
        cout<<obj.maximizeTheCuts(n,x,y,z)<<endl;
    }

	return 0;
}

// Time Complexity : O(N)
// Auxiliary Space: O(N)

// Test Case :
// 1
// 4
// 2 1 1