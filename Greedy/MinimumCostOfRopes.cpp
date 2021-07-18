#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    long long minCost(long long arr[], long long n) {
        if (n == 1)
            return 0;
        
        long long cost = 0;
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        
        for (int i = 0; i < n; ++i)
            pq.push(arr[i]);
        
        while (pq.size() != 1) {
            long long first = pq.top();
            pq.pop();
            
            long long second = pq.top();
            pq.pop();
            
            cost += first + second;
            
            pq.push(first + second);
        }
        
        return cost;
    }
};


long long minCost(long long arr[], long long n);
int main() {
    long long t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        long long i, a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        cout << ob.minCost(a, n) << endl;
    }
    return 0;
}

// Time Complexity : O(nlogn)
// Auxilliary Space : O(n)

// Test case :
// 1
// 4
// 4 3 2 6