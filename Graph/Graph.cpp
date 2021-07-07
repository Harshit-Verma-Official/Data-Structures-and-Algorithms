#include <bits/stdc++.h>
using namespace std;

class Graph {
   private:
    class Node {
       public:
        char label;
        Node(char label) {
            this->label = label;
        }
    };

    map<char, Node *> nodes;
    map<Node *, list<Node *>> adj;

    void dfs(char root, unordered_set<char> &vis) {
        cout << root << " ";
        vis.insert(root);

        for (Node *n : adj[nodes[root]])
            if (vis.find(n->label) == vis.end())
                dfs(n->label, vis);
    }

    void topoSort(char cur, unordered_set<char> &vis, stack<char> &res) {
        if (vis.find(cur) != vis.end())
            return;

        vis.insert(cur);

        for (Node *n : adj[nodes[cur]])
            topoSort(n->label, vis, res);

        res.push(cur);
    }

    bool hasCycle(char cur, unordered_set<char> &all, unordered_set<char> &visiting, unordered_set<char> &visited) {
        all.erase(cur);
        visiting.insert(cur);

        for (Node *n : adj[nodes[cur]]) {
            if (visited.find(n->label) != visited.end())
                continue;

            if (visiting.find(n->label) != visiting.end())
                return true;

            if (hasCycle(n->label, all, visiting, visited))
                return true;
        }

        visiting.erase(cur);
        visited.insert(cur);

        return false;
    }

   public:
    void addNode(char label) {
        Node *node = new Node(label);
        nodes[label] = node;
    }

    void addEdge(char from, char to) {
        if (nodes[from] == 0 or nodes[to] == 0) {
            cout << "IllegalArgumentException" << endl;
            exit(0);
        }

        adj[nodes[from]].push_back(nodes[to]);
    }

    void print() {
        for (auto itr = nodes.begin(); itr != nodes.end(); ++itr) {
            for (Node *x : adj[itr->second])
                cout << itr->first << " -> " << x->label << endl;
        }
    }

    void removeNode(char label) {
        if (nodes[label] == 0) {
            cout << "IllegalArgumentException" << endl;
            exit(0);
        }

        for (auto itr = nodes.begin(); itr != nodes.end(); itr++)
            adj[itr->second].remove(nodes[label]);

        adj.erase(nodes[label]);
        nodes.erase(label);
    }

    void removeEdge(char from, char to) {
        Node *fromNode = nodes[from];
        Node *toNode = nodes[to];

        if (!fromNode or !toNode)
            return;

        adj[fromNode].remove(toNode);
    }

    void dfs(char root) {
        if (!nodes[root])
            return;
        unordered_set<char> vis;
        dfs(root, vis);
    }

    void dfsItr(char root) {
        if (!nodes[root])
            return;

        stack<char> stack;
        unordered_set<char> vis;

        stack.push(root);
        while (!stack.empty()) {
            char top = stack.top();
            stack.pop();

            if (vis.find(top) != vis.end())
                continue;

            cout << top << " ";
            vis.insert(top);

            for (Node *n : adj[nodes[top]])
                if (vis.find(n->label) == vis.end())
                    stack.push(n->label);
        }
    }

    void bfs(char root) {
        if (!nodes[root])
            return;

        queue<char> q;
        unordered_set<char> vis;

        q.push(root);

        while (!q.empty()) {
            char cur = q.front();
            q.pop();

            if (vis.find(cur) != vis.end())
                continue;

            cout << cur << " ";
            vis.insert(cur);

            for (Node *n : adj[nodes[cur]])
                if (vis.find(n->label) == vis.end())
                    q.push(n->label);
        }
    }

    void topoSort() {
        unordered_set<char> vis;
        stack<char> res;

        for (auto itr = nodes.begin(); itr != nodes.end(); ++itr)
            topoSort(itr->first, vis, res);

        while (!res.empty()) {
            cout << res.top() << " ";
            res.pop();
        }
    }

    bool hasCycle() {
        unordered_set<char> all;
        unordered_set<char> visiting;
        unordered_set<char> visited;

        for (auto cur : nodes)
            all.insert(cur.first);

        while (!all.empty()) {
            auto cur = all.begin();
            if (hasCycle(*cur, all, visiting, visited))
                return true;
        }

        return false;
    }
};

int main() {
    Graph graph;

    graph.addNode('A');
    graph.addNode('B');
    graph.addNode('C');

    graph.addEdge('A', 'B');
    graph.addEdge('B', 'C');
    graph.addEdge('C', 'A');

    cout << graph.hasCycle();

    return 0;
}