#include <bits/stdc++.h>
#include<stdio.h>
#include<math.h>
using namespace std;

class Solution {
    public:
    long long countWays(int n, int k) {
        if (n == 0)
            return 0;
        if (n == 1)
            return k;
        
        long long mod = 1000000007;
        long long same = k % mod;
        long long diff = (k * (k - 1)) % mod;
        
        for (long long i = 3; i <= n; ++i) {
            long long prev = diff % mod;
            diff = ((same + diff) * (k - 1)) % mod;
            same = prev;
        }
        
        return (same + diff) % mod;
    }
};

int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		Solution ob;
		cout<<ob.countWays(n,k)<<endl;
	}
	return 0;
}

// Time Complexity: O(N).
// Auxiliary Space: O(1).

// Test Case : 
// 1
// 3 2