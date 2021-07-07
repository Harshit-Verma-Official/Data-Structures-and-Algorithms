#include <bits/stdc++.h>
using namespace std;


class Solution
{
    public:
    vector <int> max_of_subarrays(int *arr, int n, int k) {
        vector<int> res;
        deque<int> dq;
        
        int i;
        for (i = 0; i < k; ++i) {
            while (!dq.empty() and arr[dq.back()] <= arr[i])
                dq.pop_back();
            dq.push_back(i);
        }
        
        res.push_back(arr[dq.front()]);
        
        for (; i < n; ++i) {
            while (!dq.empty() and dq.front() <= i - k)
                dq.pop_front();
            
            while (!dq.empty() and arr[dq.back()] <= arr[i])
                dq.pop_back();
            
            dq.push_back(i);
            
            res.push_back(arr[dq.front()]);
        }
        
        return res;
    }
};


int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    
	    int n, k;
	    cin >> n >> k;
	    
	    int arr[n];
	    for(int i = 0;i<n;i++) 
	        cin >> arr[i];
	    Solution ob;
	    vector <int> res = ob.max_of_subarrays(arr, n, k);
	    for (int i = 0; i < res.size (); i++) 
	        cout << res[i] << " ";
	    cout << endl;
	    
	}
	
	return 0;
}