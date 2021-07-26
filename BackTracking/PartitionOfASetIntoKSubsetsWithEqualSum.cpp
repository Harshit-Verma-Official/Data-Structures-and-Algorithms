#include <bits/stdc++.h>
using namespace std;

class Solution{
  public:
    bool solve(int a[], int n, int k, int &subset, vector<int> &subsetSum, vector<bool> &taken, int curIdx, int lastIdx) {
        if (subsetSum[curIdx] == subset) {
            if (curIdx == k - 2)
                return true;
            return solve(a, n, k, subset, subsetSum, taken, curIdx + 1, n - 1);
        }
        
        for (int i = lastIdx; i >= 0; i--) {
            if (taken[i])
                continue;
            
            int temp = subsetSum[curIdx] + a[i];
            
            if (temp <= subset) {
                taken[i] = true;
                subsetSum[curIdx] += a[i];
                
                bool next = solve(a, n, k, subset, subsetSum, taken, curIdx, i - 1);
                
                taken[i] = false;
                subsetSum[curIdx] -= a[i];
                
                if (next)
                    return true;
            }
        }
        
        return false;
    }
    bool isKPartitionPossible(int a[], int n, int k) {
        if (k == 1)
            return true;
        
        if (k > n)
            return false;
        
        int sum = 0;
        
        for (int i = 0; i < n; ++i)
            sum += a[i];
        
        if (sum % k != 0)
            return false;
        
        vector<int> subsetSum(k, 0);
        vector<bool> taken(n, false);
        
        subsetSum[0] = a[n - 1];
        taken[n - 1] = true;
        int subset = sum / k;
        
        return solve(a, n, k, subset, subsetSum, taken, 0, n - 1);
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
    	int a[n];
    	for(int i=0;i<n;i++)
    	cin>>a[i];
    	int k;
    	cin>>k;
    	Solution obj;
    	cout<<obj.isKPartitionPossible(a, n, k)<<endl;
    }
}

// Time Complexity: O(N*2N).
// Auxiliary Space: O(2N).

// Test Case :
// 1
// 5
// 2 1 4 5 6
// 3