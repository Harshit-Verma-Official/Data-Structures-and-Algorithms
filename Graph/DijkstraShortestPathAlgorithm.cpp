#include <bits/stdc++.h>
using namespace std;

#define V 9

int vertexWithMinDistance(vector<int> &dist, vector<bool> &processed) {
    int min = INT_MAX;
    int min_idx = -1;

    for (int i = 0; i < V; ++i)
        if (!processed[i] and dist[i] <= min)
            min = dist[i], min_idx = i;

    return min_idx;
}

void printPath(vector<int> &parent, int des) {
    if (parent[des] == -1) {
        cout << des << " ";
        return;
    }

    printPath(parent, parent[des]);

    cout << des << " ";
}

void printDistances(vector<int> &dist, vector<int> &parent, int src) {
    cout << "Vertex\t Distance\tPath" << endl;
    for (int i = 0; i < V; ++i) {
        cout << src << "->" << i << "\t\t" << dist[i] << "\t\t";
        printPath(parent, i);
        cout << endl;
    }
}

void dijkstra(int graph[V][V], int src) {
    vector<int> dist(V, INT_MAX);
    vector<bool> processed(V, false);
    vector<int> parent(V, -1);

    dist[src] = 0;

    for (int count = 0; count < V - 1; ++count) {
        int u = vertexWithMinDistance(dist, processed);
        processed[u] = true;

        for (int v = 0; v < V; ++v) {
            if (!processed[v] and graph[u][v] and dist[u] != INT_MAX and dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                parent[v] = u;
            }
        }
    }

    printDistances(dist, parent, src);
}

int main() {
    int graph[V][V] = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
                       {4, 0, 8, 0, 0, 0, 0, 11, 0},
                       {0, 8, 0, 7, 0, 4, 0, 0, 2},
                       {0, 0, 7, 0, 9, 14, 0, 0, 0},
                       {0, 0, 0, 9, 0, 10, 0, 0, 0},
                       {0, 0, 4, 0, 10, 0, 2, 0, 0},
                       {0, 0, 0, 14, 0, 2, 0, 1, 6},
                       {8, 11, 0, 0, 0, 0, 1, 0, 7},
                       {0, 0, 2, 0, 0, 0, 6, 7, 0}};

    dijkstra(graph, 0);

    return 0;
}