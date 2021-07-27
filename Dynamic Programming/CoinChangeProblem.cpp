// Given a value N, find the number of ways to make change for N cents, 
// if we have infinite supply of each of S = { S1, S2, .. , SM } valued coins.

#include<bits/stdc++.h>
using namespace std;

class Solution
{
  public:
    long long int count( int S[], int m, int n) {
        if (n == 0)
            return 1;
        
        vector<long long int> table(n + 1, 0);
        table[0] = 1;
        
        for (int i = 0; i < m; ++i)
            for (int j = S[i]; j <= n; ++j)
                table[j] += table[j - S[i]];
        
        return table[n];
    }
};

int main()
{
    int t;
    cin>>t;
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		int arr[m];
		for(int i=0;i<m;i++)
		    cin>>arr[i];
	    Solution ob;
		cout<<ob.count(arr,m,n)<<endl;
	}
    
    
    return 0;
}

// Time Complexity: O(m*n).
// Auxiliary Space: O(n).

// Test Case : 
// 1
// 4 3
// 1 2 3
