#include <bits/stdc++.h>
using namespace std;

bool isSafe(int cur, int curColor, int V, int color[], bool graph[101][101]) {
    for (int v = 0; v < V; ++v)
        if (v != cur and graph[cur][v] and color[v] == curColor)
            return false;
    return true;
}

bool solve(int cur, int V, int m, int color[], bool graph[101][101]) {
    if (cur == V)
        return true;
    
    for (int i = 1; i <= m; ++i) {
        if (isSafe(cur, i, V, color, graph)) {
            color[cur] = i;
            if (solve(cur + 1, V, m, color, graph))
                return true;
            color[cur] = 0;
        }
    }
    
    return false;
}

//Function to determine if graph can be coloured with at most M colours such
//that no two adjacent vertices of graph are coloured with same colour.
bool graphColoring(bool graph[101][101], int m, int V) {
    int color[V] = { 0 };
    return solve(0, V, m, color, graph);
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        cout << graphColoring(graph, m, n) << endl;
    }
    return 0;
}

// Time : O(V^M)
// Space : O(M) + O(N)
// https://practice.geeksforgeeks.org/problems/m-coloring-problem-1587115620/1