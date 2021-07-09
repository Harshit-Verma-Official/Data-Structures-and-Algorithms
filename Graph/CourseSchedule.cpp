#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    bool hasCycle(int cur, vector<vector<int>> &adj, vector<bool> &visited, vector<bool> &visiting) {
        visiting[cur] = true;
        
        for (auto x : adj[cur]) {
            if (visiting[x])
                return true;
            if (!visited[x] and hasCycle(x, adj, visited, visiting))
                return true;
        }
        
        visited[cur] = true;
        visiting[cur] = false;
        
        return false;
    }
    
    bool canFinish(int N, vector<vector<int>>& pre) {
        vector<vector<int>> adj(N);
        
        for (int i = 0; i < pre.size(); ++i)
            adj[pre[i][0]].push_back(pre[i][1]);
        
        vector<bool> visited(N, false);
        vector<bool> visiting(N, false);
        
        for (int i = 0; i < N; ++i)
            if (!visited[i] and hasCycle(i, adj, visited, visiting))
                return false;
        
        return true;
    }
};

int main() {

	int n;
	int nPre;

	cin >> n >> nPre;

	vector<vector<int>> pre;

	for (int i = 0; i < nPre; ++i) {
		int u;
		int v;
		cin >> u >> v;
		pre.push_back({u, v});
	}

	Solution solve;

	cout << solve.canFinish(n, pre);

	return 0;
}

// https://leetcode.com/problems/course-schedule/