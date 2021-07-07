
// Program to find Dijkstra's shortest path using
// priority_queue in STL

#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> iPair;

void addEdge(vector<pair<int, int>> adj[], int u, int v, int wt) {
    adj[u].push_back({v, wt});
    adj[v].push_back({u, wt});
}

void printPath(unordered_map<int, int> &parent, int dest) {
    if (parent.find(dest) == parent.end()) {
        cout << dest << " ";
        return;
    }

    printPath(parent, parent[dest]);

    cout << dest << " ";
}

void print(vector<int> &dist, int V, unordered_map<int, int> &parent, int src) {
    for (int i = 0; i < V; ++i) {
        cout << src << "->" << i << "\t\t" << dist[i] << "\t\t ";
        printPath(parent, i);
        cout << endl;
    }
}

void shortestPath(vector<pair<int, int>> adj[], int V, int src) {
    priority_queue<iPair, vector<iPair>, greater<iPair>> pq;
    unordered_map<int, int> parent;

    vector<int> dist(V, INT_MAX);

    pq.push({0, src});
    dist[src] = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for (auto x : adj[u]) {
            int v = x.first;
            int weight = x.second;

            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                parent[v] = u;
                pq.push({dist[v], v});
            }
        }
    }

    cout << "Vertex\t Distance\tPath" << endl;
    print(dist, V, parent, src);
}

int main() {
    int V = 9;
    vector<iPair> adj[V];

    // making above shown graph
    addEdge(adj, 0, 1, 4);
    addEdge(adj, 0, 7, 8);
    addEdge(adj, 1, 2, 8);
    addEdge(adj, 1, 7, 11);
    addEdge(adj, 2, 3, 7);
    addEdge(adj, 2, 8, 2);
    addEdge(adj, 2, 5, 4);
    addEdge(adj, 3, 4, 9);
    addEdge(adj, 3, 5, 14);
    addEdge(adj, 4, 5, 10);
    addEdge(adj, 5, 6, 2);
    addEdge(adj, 6, 7, 1);
    addEdge(adj, 6, 8, 6);
    addEdge(adj, 7, 8, 7);

    shortestPath(adj, V, 0);

    return 0;
}