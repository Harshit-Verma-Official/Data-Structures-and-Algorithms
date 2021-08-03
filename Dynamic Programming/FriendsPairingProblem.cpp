#include <bits/stdc++.h> 
using namespace std; 

class Solution
{
public:
    int countFriendsPairings(int n) {
        if (n <= 2)
            return n;
            
        int mod = 1000000007;
        int a = 1, b = 2, c = 0;
        
        for (long long i = 3; i <= n; ++i) {
            c = ((b % mod) + ((i - 1) * a) % mod) % mod;
            a = b;
            b = c;
        }
        
        return c;
    }
};    
 

int main() 
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	cin>>n;
    	Solution ob;
    	cout <<ob.countFriendsPairings(n); 
    	cout<<endl;
    }
} 

// Time Complexity: O(N)
// Auxiliary Space: O(1)

// Test Case :
// 1
// 4