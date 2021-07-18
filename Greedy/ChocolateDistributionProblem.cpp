#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    long long findMinDiff(vector<long long> a, long long n, long long m) {
        sort(a.begin(), a.end());
        
        long long res = INT_MAX;
        for (int i = 0; i <= n - m; ++i)
            res = min(res, a[i + m - 1] - a[i]);
        
        return res;
    }   
};

int main() {
	long long t;
	cin>>t;
	while(t--)
	{
		long long n;
		cin>>n;
		vector<long long> a;
		long long x;
		for(long long i=0;i<n;i++)
		{
			cin>>x;
			a.push_back(x);
		}
		
		long long m;
		cin>>m;
		Solution ob;
		cout<<ob.findMinDiff(a,n,m)<<endl;
	}
	return 0;
}

// Time Complexity: O(N*Log(N))
// Auxiliary Space: O(1)

// Test case :
// 1
// 8
// 3 4 1 9 56 7 9 12
// 5