#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(int cur, unordered_map<int, vector<int>> &adj, vector<bool> &vis) {
        vis[cur] = true;
        for (int i = 0; i < adj[cur].size(); ++i)
            if (!vis[adj[cur][i]])
                dfs(adj[cur][i], adj, vis);
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        int edges = connections.size();
        
        if (edges < n - 1)
            return -1;
        
        vector<bool> vis(n, false);
        unordered_map<int, vector<int>> adj;
        
        for (int i = 0; i < connections.size(); ++i) {
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
        }
        
        int nComponent = 0;
        for (int i = 0; i < n; ++i) {
            if (!vis[i]) {
                dfs(i, adj, vis);
                nComponent++;
            }
        }
        
        int redundantEdges = edges - ((n - 1) - (nComponent - 1));
        
        return redundantEdges >= nComponent - 1 ? nComponent - 1 : -1;
    }
};

int main() {

	int n;
	int nConnections;
	vector<vector<int>> connections;

	cin >> n >> nConnections;


	int a;
	int b;
	for (int i = 0; i < nConnections; ++i) {
		cin >> a >> b;
		connections.push_back({a, b});
	}

	Solution solve;

	cout << solve.makeConnected(n, connections);

	return 0;
}

// Input Format:
// n(no. of computers) m(no. of connections)
// m lines each containing: a(connection from) b(connection to)