#include <bits/stdc++.h>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int arr[], long long int n, long long int k);

// Test Case
// 1
// 5
// -8 2 3 -6 10
// 2

int main() {
    long long int t, i;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        long long int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        long long int k;
        cin >> k;

        vector<long long> ans = printFirstNegativeInteger(arr, n, k);
        for (auto it : ans) cout << it << " ";
        cout << endl;
    }
    return 0;
}

vector<long long> printFirstNegativeInteger(long long int arr[], long long int n, long long int k) {
    vector<long long> res;
    deque<long long int> dq;
    
    int i;
    for (i = 0; i < k; ++i)
        if (arr[i] < 0)
            dq.push_back(i);
    
    long long ans = dq.empty() ? 0 : arr[dq.front()];
    res.push_back(ans);
    
    for (; i < n; ++i) {
        while (!dq.empty() and dq.front() <= i - k)
            dq.pop_front();
        
        if (arr[i] < 0)
            dq.push_back(i);
        
        ans = dq.empty() ? 0 : arr[dq.front()];
        res.push_back(ans);
    }
    
    return res;
}