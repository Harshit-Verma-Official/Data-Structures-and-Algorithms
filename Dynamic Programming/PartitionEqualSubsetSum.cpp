#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int equalPartition(int n, int arr[]) {
        int sum = 0;
        
        for (int i = 0; i < n; ++i)
            sum += arr[i];
        
        if (sum & 1)
            return false;
        
        sum /= 2;
        
        bool dp[n + 1][sum + 1];
        
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j <= sum; ++j) {
                if (i == 0)
                    dp[i][j] = false;
                else if (j == 0)
                    dp[i][j] = true;
                else if (arr[i - 1] > j)
                    dp[i][j] = dp[i - 1][j];
                else
                    dp[i][j] = dp[i - 1][j] or dp[i - 1][j - arr[i - 1]];
            }
        }
        
        return dp[n][sum];
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}

// Time Complexity: O(N*sum of elements)
// Auxiliary Space: O(N*sum of elements)

// Test Case : 
// 1
// 4
// 1 5 11 5