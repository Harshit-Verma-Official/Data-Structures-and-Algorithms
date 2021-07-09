#include <bits/stdc++.h>
using namespace std;

void print(vector<int> &arr) {
	for (int i = 0; i < arr.size(); ++i)
		cout << arr[i] << " ";
	cout << endl;
}

void dfs(int cur, vector<int> adj[], vector<bool> &visited, stack<int> &stack) {
	visited[cur] = true;

	for (int i = 0; i < adj[cur].size(); ++i)
		if (!visited[adj[cur][i]])
			dfs(adj[cur][i], adj, visited, stack);

	stack.push(cur);
}

vector<int> topoSortDFS(int V, vector<int> adj[]) {
	vector<int> res;

	vector<bool> visited(V, false);
	stack<int> stack;

	for (int i = 0; i < V; ++i)
		if (!visited[i])
			dfs(i, adj, visited, stack);

	while (!stack.empty()) {
		res.push_back(stack.top());
		stack.pop();
	}

	print(res);
}

void topoSortBFS(int V, vector<int> adj[]) {
	vector<int> res;

	vector<int> inDegree(V, 0);
	queue<int> q;

	for (int i = 0; i < V; ++i)
		for (auto x : adj[i])
			inDegree[x]++;

	for (int i = 0; i < V; ++i)
		if (inDegree[i] == 0)
			q.push(i);

	while (!q.empty()) {
		int top = q.front();
		q.pop();

		res.push_back(top);

		for (auto v : adj[top]) {
			inDegree[v]--;
			if (inDegree[v] == 0)
				q.push(v);
		}
	}

	print(res);
}

int main() {
	int V;
	int E;
	int u, v;

	cin >> V >> E;

	vector<int> adj[V];

	for (int i = 0; i < E; ++i) {
		cin >> u >> v;
		adj[u].push_back(v);
	}

	topoSortBFS(V, adj);

	return 0;
}

// Time Complexity: O(V + E).
// Auxiliary Space: O(V).