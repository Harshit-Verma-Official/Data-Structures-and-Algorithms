#include <bits/stdc++.h>
using namespace std;

int getMinEdgeReversal(int V, int E, vector<pair<int, int>> &adj, int src, int dest) {
	vector<bool> vis(V, false);
	vector<int> dist(V, INT_MAX);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	vector<pair<int, int>> modified[V];

	for (int i = 0; i < E; ++i) {
		modified[adj[i].first].push_back({adj[i].second, 0});
		modified[adj[i].second].push_back({adj[i].first, 1});
	}

	dist[src] = 0;
	pq.push({0, src});

	while (!pq.empty()) {
		int u = pq.top().second;
		pq.pop();

		for (auto x : modified[u]) {
			int v = x.first;
			int wt = x.second;
			if (dist[u] + wt < dist[v]) {
				dist[v] = dist[u] + wt;
				pq.push({dist[v], v});
			}
		}
	}

	return dist[dest] == INT_MAX ? -1 : dist[dest];
}

int main() {
	int V;
	int E;
	int src;
	int dest;

	cin >> V >> E >> src >> dest;

	vector<pair<int, int>> adj;

	for (int i = 0; i < E; ++i) {
		int u, v;
		cin >> u >> v;
		adj.push_back({u, v});
	}

	cout << getMinEdgeReversal(V, E, adj, src, dest);

	return 0;
}