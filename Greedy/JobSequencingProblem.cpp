// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 

class Solution 
{
    public:
    static bool comp(Job &a, Job &b) {
        return a.profit > b.profit;
    }
    vector<int> JobScheduling(Job arr[], int n) {
        sort(arr, arr + n, comp);
        
        int maxt = arr[0].dead;
        for (int i = 0; i < n; ++i)
            maxt = max(maxt, arr[i].dead);
        
        vector<int> slots(n + 1, -1);
        
        vector<int> res(2, 0);
        for (int i = 0; i < n; ++i) {
            for (int j = arr[i].dead; j > 0; --j) {
                if (slots[j] == -1) {
                    slots[j] = i;
                    res[0]++;
                    res[1] += arr[i].profit;
                    break;
                }
            }
        }
        
        return res;
    } 
};

int main() 
{ 
    int t;
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}

// Time Complexity : O(NlogN) + O(V * sizeof(slots))
// Space Complexity : O(M)