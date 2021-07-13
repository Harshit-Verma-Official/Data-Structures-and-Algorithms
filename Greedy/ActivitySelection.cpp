#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    static bool comp(pair<int, int> &a, pair<int, int> &b) {
        if (a.second == b.second)
            return a.first < b.first;
        return a.second < b.second;
    }
    int maxMeetings(int start[], int end[], int n) {
        vector<pair<int, int>> act;
        
        for (int i = 0; i < n; ++i)
            act.push_back({start[i], end[i]});
        
        sort(act.begin(), act.end(), comp);
        
        int i = 0;
        int j = 1;
        int count = 1;
        
        while (j < n) {
            if (act[i].second < act[j].first) {
                count++;
                i = j;
                j++;
            } else
                j++;
        }
        
        return count;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}

// Time Complexity : O(N*LogN)
// Auxilliary Space : O(N)

