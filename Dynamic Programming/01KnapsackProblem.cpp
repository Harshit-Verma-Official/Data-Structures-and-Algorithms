#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

class Solution
{
    public:
    int solve(int w, int wt[], int val[], int i, vector<vector<int>> &dp) {
        if (w <= 0 or i < 0)
            return 0;
        
        if (dp[i][w] != -1)
            return dp[i][w];
        
        int result;
        
        if (wt[i] > w)
            result = solve(w, wt, val, i - 1, dp);
        else
            result = max(val[i] + solve(w - wt[i], wt, val, i - 1, dp), 
                                  solve(w, wt, val, i - 1, dp));
        
        return dp[i][w] = result;
    }
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) {
        vector<vector<int>> dp(n, vector<int>(W + 1, -1));
        
        return solve(W, wt, val, n - 1, dp);
    }
};

// { Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
    return 0;
}  // } Driver Code Ends


// Time Complexity: O(N*W)
// Auxiliary Space: O(N*W)

// Test Case : 
// 1
// 3
// 4
// 1 2 3
// 4 5 1
