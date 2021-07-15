// Program to find minimum number of platforms
// required on a railway station
#include <bits/stdc++.h>
using namespace std;


class Solution{
    public:
    int findPlatform(int arr[], int dep[], int n)
    {
    	sort(arr, arr + n);
    	sort(dep, dep + n);
    	
    	int i = 1;
    	int j = 0;
    	int ans = 1;
    	int p = 1;
    	
    	while (i < n and j < n) {
    	    if (dep[j] >= arr[i]) {
    	        ans = max(ans, ++p);
    	        i++;
    	    } else {
    	        p--;
    	        j++;
    	    }
    	}
    	
    	return ans;
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
        int arr[n];
        int dep[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        for(int j=0;j<n;j++){
            cin>>dep[j];
        }
        Solution ob;
        cout <<ob.findPlatform(arr, dep, n)<<endl;
    } 
   return 0;
}

// Time : O(2NlogN) + O(2N)
// Space : O(1)

// Input: n = 6 
// arr[] = {0900, 0940, 0950, 1100, 1500, 1800}
// dep[] = {0910, 1200, 1120, 1130, 1900, 2000}
// Output: 3

// Test case
// 1
// 6
// 0900 0940 0950 1100 1500 1800
// 0910 1200 1120 1130 1900 2000