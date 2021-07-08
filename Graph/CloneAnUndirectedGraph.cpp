#include <bits/stdc++.h>
using namespace std;

class Node {
   public:
    int val;
    vector<Node *> neighbors;
    Node(int val) {
        this->val = val;
    }
};

void dfs(Node *cur, Node *node, vector<Node *> &visited) {
    for (auto n : cur->neighbors) {
        if (visited[n->val] == NULL) {
            Node *newNode = new Node(n->val);
            (node->neighbors).push_back(newNode);
            visited[newNode->val] = newNode;
            dfs(n, newNode, visited);
        } else
            (node->neighbors).push_back(visited[n->val]);
    }
}

Node *cloneGraph(Node *node) {
    if (!node)
        return node;

    vector<Node *> visited(101, NULL);
    Node *copy = new Node(node->val);
    visited[copy->val] = copy;

    for (auto n : node->neighbors) {
        if (visited[n->val] == NULL) {
            Node *newNode = new Node(n->val);
            (copy->neighbors).push_back(newNode);
            visited[newNode->val] = newNode;
            dfs(n, newNode, visited);
        } else
            (copy->neighbors).push_back(visited[n->val]);
    }

    return copy;
}

// Build the desired graph
Node *buildGraph() {
    /*
        Note : All the edges are Undirected
        Given Graph:
        1--2
        | |
        4--3
    */
    Node *node1 = new Node(1);
    Node *node2 = new Node(2);
    Node *node3 = new Node(3);
    Node *node4 = new Node(4);
    vector<Node *> v;
    v.push_back(node2);
    v.push_back(node4);
    node1->neighbors = v;
    v.clear();
    v.push_back(node1);
    v.push_back(node3);
    node2->neighbors = v;
    v.clear();
    v.push_back(node2);
    v.push_back(node4);
    node3->neighbors = v;
    v.clear();
    v.push_back(node3);
    v.push_back(node1);
    node4->neighbors = v;
    return node1;
}

// A simple bfs traversal of a graph to
// check for proper cloning of the graph
void bfs(Node *src) {
    map<Node *, bool> visit;
    queue<Node *> q;
    q.push(src);
    visit[src] = true;
    while (!q.empty()) {
        Node *u = q.front();
        cout << "Value of Node " << u->val << "\n";
        cout << "Address of Node " << u << "\n";
        q.pop();
        vector<Node *> v = u->neighbors;
        int n = v.size();
        for (int i = 0; i < n; i++) {
            if (!visit[v[i]]) {
                visit[v[i]] = true;
                q.push(v[i]);
            }
        }
    }
    cout << endl;
}

// Driver program to test above function
int main() {
    Node *src = buildGraph();
    cout << "BFS Traversal before cloning\n";
    bfs(src);
    Node *newsrc = cloneGraph(src);
    cout << "BFS Traversal after cloning\n";
    bfs(newsrc);
    return 0;
}

// Time Complexity : O(E * V)