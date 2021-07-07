#include <bits/stdc++.h>
using namespace std;

struct Node {
    int parent;
    int rank;
};

int find(vector<Node> &dsuf, int v) {
    if (dsuf[v].parent == -1)
        return v;
    return dsuf[v].parent = find(dsuf, dsuf[v].parent);
}

void union_op(vector<Node> &dsuf, int fromP, int toP) {
    fromP = find(dsuf, fromP);
    toP = find(dsuf, toP);

    if (dsuf[fromP].rank > dsuf[toP].rank)
        dsuf[toP].parent = fromP;
    else if (dsuf[fromP].rank < dsuf[toP].rank)
        dsuf[fromP].parent = toP;
    else {
        dsuf[fromP].parent = toP;
        dsuf[toP].rank += 1;
    }
}

bool hasCycle(int V, vector<pair<int, int>> &edge_list) {
    vector<Node> dsuf(V);

    for (int i = 0; i < V; ++i) {
        dsuf[i].parent = -1;
        dsuf[i].rank = 0;
    }

    for (auto p : edge_list) {
        int fromP = find(dsuf, p.first);
        int toP = find(dsuf, p.second);

        if (fromP == toP)
            return true;

        union_op(dsuf, fromP, toP);
    }

    return false;
}

int main() {
    int V;
    int E;

    cin >> V >> E;

    vector<pair<int, int>> edge_list;
    for (int i = 0; i < E; ++i) {
        int from;
        int to;
        cin >> from >> to;
        edge_list.push_back({from, to});
    }

    if (hasCycle(V, edge_list))
        cout << "TRUE" << endl;
    else
        cout << "FALSE" << endl;

    return 0;
}