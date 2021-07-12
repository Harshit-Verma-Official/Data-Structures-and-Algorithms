#include <bits/stdc++.h>
using namespace std;

const int V = 5;

bool isBipartiteUtil(int G[][V], int src, vector<int> &color) {
	color[src] = 1;

	queue<int> q;
	q.push(src);

	while (!q.empty()) {
		int u = q.front();
		q.pop();

		for (int v = 0; v < V; ++v) {
			if (G[u][v] and color[v] == -1) {
				color[v] = 1 - color[u];
				q.push(v);
			} else if (G[u][v] and color[u] == color[v])
				return false;
		}
	}

	return true;
}

bool isBipartite(int G[][V]) {
	vector<int> color(V, -1);

	for (int i = 0; i < V; ++i)
		if (color[i] == -1)
			if (!isBipartiteUtil(G, i, color))
				return false;
	return true;
}

bool canBeDividedinTwoCliques(int G[][V]) {
	int GC[V][V];

	for (int i = 0; i < V; ++i)
		for (int j = 0; j < V; ++j)
			GC[i][j] = (i != j) ? !G[i][j] : 0;

	return isBipartite(GC);
}

int main() {
	int G[][V] = {{0, 1, 1, 1, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 0, 0},
        {0, 1, 0, 0, 1},
        {0, 0, 0, 1, 0}
    };
  
    canBeDividedinTwoCliques(G) ? cout << "Yes" :
                                  cout << "No";
    return 0;
}

// Time complexity of above implementation is O(V2).