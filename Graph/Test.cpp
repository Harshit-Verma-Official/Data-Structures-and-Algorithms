#include <bits/stdc++.h>
using namespace std;

#define V 6

int minValueVertex(vector<int> &dist, vector<bool> &processed) {
    int min = INT_MAX;
    int vertex = -1;
    for (int i = 0; i < V; ++i) {
        if (!processed[i] and dist[i] < min) {
            min = dist[i];
            vertex = i;
        }
    }
    return vertex;
}

void findMST(int graph[V][V]) {
    int parent[V];
    vector<int> dist(V, INT_MAX);
    vector<bool> processed(V, false);

    parent[0] = -1;
    dist[0] = 0;

    for (int i = 0; i < V -1; ++i) {
        int u = minValueVertex(dist, processed);
        processed[u] = true;

        for (int j = 0; j < V; ++j) {
            if (graph[u][j] and !processed[j] and graph[u][j] < dist[j]) {
                dist[j] = graph[u][j];
                parent[j] = u;
            }
        }
    }

    for (int i = 1; i < V; ++i)
        cout << parent[i] << "->" << i << " || Weight = " << dist[i] << endl;
}

int main() {
    int graph[V][V] = {{0, 4, 6, 0, 0, 0},
                       {4, 0, 6, 3, 4, 0},
                       {6, 6, 0, 1, 8, 0},
                       {0, 3, 1, 0, 2, 3},
                       {0, 4, 8, 2, 0, 7},
                       {0, 0, 0, 3, 7, 0}};

    findMST(graph);
    return 0;
}