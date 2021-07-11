#include <bits/stdc++.h>
using namespace std;

void topoSort(int cur, vector<pair<int, int>> adj[], vector<bool> &visited, stack<int> &stack) {
	visited[cur] = true;

	for (auto x : adj[cur])
		if (!visited[x.first])
			topoSort(x.first, adj, visited, stack);

	stack.push(cur);
}

void shortestPath(int src, int V, vector<pair<int, int>> adj[]) {
	stack<int> stack;
	vector<bool> visited(V, false);

	for (int i = 0; i < V; ++i)
		if (!visited[i])
			topoSort(i, adj, visited, stack);

	vector<int> dist(V, INT_MAX);
	dist[src] = 0;

	while (!stack.empty()) {
		int top = stack.top();
		stack.pop();

		if (dist[top] != INT_MAX)
			for (auto x : adj[top])
				if (dist[top] + x.second < dist[x.first])
					dist[x.first] = dist[top] + x.second;
	}

	for (int i = 0; i < V; ++i)
		dist[i] == INT_MAX ? cout << "INF" : cout << dist[i] << " ";
}

int main() {

	int V;
	int E;
	int src;

	cin >> V >> E >> src;

	vector<pair<int, int>> adj[V];

	for (int i = 0; i < E; ++i) {
		int u, v, wt;
		cin >> u >> v >> wt;
		adj[u].push_back({v, wt});
	}

	shortestPath(src, V, adj);

	return 0;
}

// Time : O(V + E)
// Space : O(2V)

// Test Case
// 6 7 0
// 0 1 2
// 0 4 1
// 1 2 3
// 2 3 6
// 4 2 2
// 4 5 4
// 5 3 1