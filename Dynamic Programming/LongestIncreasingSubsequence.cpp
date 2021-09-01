#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    int longestSubsequence(int n, int a[]) {
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = INT_MIN;
        
        for (int i = 0; i < n; ++i) {
            int idx = lower_bound(dp.begin(), dp.end(), a[i]) - dp.begin();
            dp[idx] = min(dp[idx], a[i]);
        }
        
        int ans = 0;
        
        for (int i = n; i >= 0; --i) {
            if (dp[i] != INT_MAX) {
                ans = i;
                break;
            }
        }
        
        return ans;
    }
};

int main() {
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}

// Time Complexity : O( N*log(N) )
// Auxiliary Space: O(N)

// Test Case
// 1
// 16
// 0 8 4 12 2 10 6 14 1 9 5 13 3 11 7 15