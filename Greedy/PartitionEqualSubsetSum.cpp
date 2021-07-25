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
            
        bool dp[n + 1][sum + 1];
        sum /= 2;
        
        for (int i = 0; i <= n; ++i)
            dp[i][0] = true;
        for (int i = 1; i <= sum; ++i)
            dp[0][i] = false;
        
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= sum; ++j) {
                if (arr[i - 1] > j)
                    dp[i][j] = dp[i - 1][j];
                else if (arr[i - 1] <= j)
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

// Test case :
// 1
// 4
// 1 5 11 5