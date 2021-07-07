#include <bits/stdc++.h>
using namespace std;

struct Node {
	int parent;
	int rank;
};

struct Edge {
	int from;
	int to;
	int wt;
};

int find(vector<Node> &dsuf, int v) {
	if (dsuf[v].parent == -1)
		return v;
	return dsuf[v].parent = find(dsuf, dsuf[v].parent);
}

void union_op(vector<Node> &dsuf, int fromP, int toP) {
	if (dsuf[fromP].rank > dsuf[toP].rank)
		dsuf[toP].parent = fromP;
	else if (dsuf[fromP].rank < dsuf[toP].rank)
		dsuf[fromP].parent = toP;
	else {
		dsuf[fromP].parent = toP;
		dsuf[toP].rank += 1;
	}
}

void printMst(vector<Edge> edgeList) {
	for (auto edge : edgeList)
		cout << edge.from << " -> " << edge.to << " || Weight : " << edge.wt << endl;
}

bool comp(Edge a, Edge b) {
	return a.wt < b.wt;
}

vector<Edge> Kruskals(int V, vector<Edge> &edgeList) {
	vector<Edge> mst;

	vector<Node> dsuf(V);
	for (int i = 0; i < V; ++i) {
		dsuf[i].parent = -1;
		dsuf[i].rank = 0;
	}

	sort(edgeList.begin(), edgeList.end(), comp);

	int i = 0;
	int j = 0;

	while (i < V - 1 and j < edgeList.size()) {
		int fromP = find(dsuf, edgeList[j].from);
		int toP = find(dsuf, edgeList[j].to);

		if (fromP == toP) {
			j++;
			continue;
		}

		union_op(dsuf, fromP, toP);
		mst.push_back(edgeList[j]);
		i++;
	}

	return mst;
}

int main() {
	int V;
	int E;

	cin >> V >> E;

	vector<Node> dsuf(V);
	for (int i = 0; i < V; ++i) {
		dsuf[i].parent = -1;
		dsuf[i].rank = 0;
	}

	vector<Edge> edgeList;
	for(int i = 0; i < E; ++i) {
		Edge temp;
		int from;
		int to;
		int wt;

		cin >> temp.from >> temp.to >> temp.wt;

		edgeList.push_back(temp);
	}


	printMst(Kruskals(V, edgeList));

	return 0;
}