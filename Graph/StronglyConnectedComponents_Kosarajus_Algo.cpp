#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    void dfs1(int cur, vector<int> adj[], vector<bool> &visited, stack<int> &stack) {
        visited[cur] = true;
        for (auto x : adj[cur])
            if (!visited[x])
                dfs1(x, adj, visited, stack);
        stack.push(cur);
    }
    void reverse(int V, vector<int> adj[], vector<vector<int>> &rev) {
        for (int i = 0; i < V; ++i)
            for (auto x : adj[i])
                rev[x].push_back(i);
    }
    void dfs2(int cur, vector<vector<int>> &rev, vector<bool> &visited) {
        visited[cur] = true;
        for (auto x : rev[cur])
            if (!visited[x])
                dfs2(x, rev, visited);
    }
    int kosaraju(int V, vector<int> adj[]) {
        stack<int> stack;
        vector<vector<int>> rev(V);
        vector<bool> visited(V, false);

        for (int i = 0; i < V; ++i)
            if (!visited[i])
                dfs1(i, adj, visited, stack);

        for (int i = 0; i < V; ++i)
            visited[i] = false;

        reverse(V, adj, rev);

        int count = 0;

        while (!stack.empty()) {
            int top = stack.top();
            stack.pop();

            if (!visited[top]) {
                count++;
                dfs2(top, rev, visited);
            }
        }

        return count;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}

// Time Complexity: O(V+E).
// Auxiliary Space: O(V).

// Test Case
// 1
// 5 5
// 1 0
// 0 2
// 2 1
// 0 3
// 3 4