#include <bits/stdc++.h>
using namespace std;

class UndirectedGraph {
    class Node;
    class Edge;

   private:
    class Node {
       private:
        list<Edge *> edges;

       public:
        char label;
        Node(char label) {
            this->label = label;
        }

        void addEdge(Node *to, int weight) {
            edges.push_back(new Edge(this, to, weight));
        }

        list<Edge *> getEdges() {
            return edges;
        }
    };
    class Edge {
       public:
        Node *from;
        Node *to;
        int weight;
        Edge(Node *from, Node *to, int weight) {
            this->from = from;
            this->to = to;
            this->weight = weight;
        }
    };

    map<char, Node *> nodes;

   public:
    void addNode(char label) {
        nodes[label] = new Node(label);
    }

    void addEdge(char from, char to, int weight) {
        if (!nodes[from] or !nodes[to]) {
            cout << "IllegalArgumentException" << endl;
            exit(0);
        }

        Node *fromNode = nodes[from];
        Node *toNode = nodes[to];

        fromNode->addEdge(toNode, weight);
        toNode->addEdge(fromNode, weight);
    }

    void print() {
        for (auto itr : nodes) {
            cout << itr.first << " is connected to : ";
            for (auto edge : itr.second->getEdges())
                cout << "[" << edge->from->label << "->" << edge->to->label << "]"
                     << " ";
            cout << endl;
        }
    };
};

int main() {
    UndirectedGraph graph;

    graph.addNode('A');
    graph.addNode('B');
    graph.addNode('C');

    graph.addEdge('A', 'B', 3);
    graph.addEdge('A', 'C', 2);

    graph.print();

    return 0;
}