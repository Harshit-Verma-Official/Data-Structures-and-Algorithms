#include <bits/stdc++.h>
using namespace std;

struct Edge {
	int from;
	int to;
	int wt;
};

void bellmanFord(int v, int e, vector<Edge> &edges, int src) {
	vector<int> dist(v, INT_MAX);
	int parent[v];

	dist[src] = 0;
	parent[src] = -1;

	bool updated = false;

	for (int i = 0; i < v - 1; ++i) {
		updated = false;

		for (int j = 0; j < e; ++j) {
			int u = edges[j].from;
			int v = edges[j].to;
			int wt = edges[j].wt;
			if (dist[u] != INT_MAX and dist[u] + wt < dist[v]) {
				dist[v] = dist[u] + wt;
				parent[v] = u;
				updated = true;
			}
		}

		if (!updated)
			break;
	}

	for (int i = 0; i < e and updated; ++i) {
		int u = edges[i].from;
		int v = edges[i].to;
		int wt = edges[i].wt;
		if (dist[u] != INT_MAX and dist[u] + wt < dist[v]) {
			cout << "Graph has -ve Edge Cycle!\n";
			return;
		}
	}

	cout << "Vertex\tDistance\n";
	for (int i = 0; i < v; ++i)
		cout << src << "->" << i << "\t\t" << dist[i] << endl;
}

int main() {
	int v;
	int e;

	cin >> v >> e;

	vector<Edge> edges(e);
	for (int i = 0; i < e; ++i) {
		cin >> edges[i].from;
		cin >> edges[i].to;
		cin >> edges[i].wt;
	}

	bellmanFord(v, e, edges, 0);

	return 0;
}