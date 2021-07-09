#include <bits/stdc++.h>
using namespace std;

int main() {

	int V;
	int E;
	int u;
	int v;

	cin >> V >> E;

	vector<int> adj[V + 1];
	vector<int> inDegree(V + 1, 0);

	for (int i = 0; i < E; ++i) {
		cin >> u >> v;
		adj[u].push_back(v);
		inDegree[v]++;
	}

	vector<int> res(V + 1);
	queue<int> q;

	for (int i = 1; i <= V; ++i){
		if (inDegree[i] == 0){
			q.push(i); 
			res[i] = 1;
		}
	}

	while (!q.empty()) {
		int top = q.front();
		q.pop();

		for (auto v : adj[top]) {
			inDegree[v]--;
			if (inDegree[v] == 0) {
				res[v] = res[top] + 1;
				q.push(v);
			}
		}
	}

	for (int i = 1; i <= V; ++i)
		cout << res[i] << " ";

	return 0;
}

// Time Complexity: O(V+E), where V is the number of nodes and E is the number of edges. 
// Auxiliary Space: O(V)