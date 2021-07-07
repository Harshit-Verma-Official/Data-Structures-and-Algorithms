#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int r;
    int c;
    int e;
    Node *next;
    Node(int r, int c, int e) {
        this->r = r;
        this->c = c;
        this->e = e;
        next = nullptr;
    }
};

void createNode(Node *&head, int r, int c, int e) {
    if (head == nullptr) {
        head = new Node(r, c, e);
        return;
    }

    Node *current = head;
    while (current->next != nullptr)
        current = current->next;

    current->next = new Node(r, c, e);
}

int main() {

    int sparseMatrix[4][5] = {{0, 0, 3, 0, 4},
                              {0, 0, 5, 7, 0},
                              {0, 0, 0, 0, 0},
                              {0, 2, 6, 0, 0}};

    Node *compact = nullptr;

    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 5; ++j)
            if (sparseMatrix[i][j] != 0)
                createNode(compact, i, j, sparseMatrix[i][j]);

    Node *current = compact;
    cout << "Row No's. : ";
    while (current != nullptr) {
        cout << current->r << " ";
        current = current->next;
    }
    cout << endl;

    current = compact;
    cout << "Column No's. : ";
    while (current != nullptr) {
        cout << current->c << " ";
        current = current->next;
    }
    cout << endl;
    current = compact;
    cout << "Elements : ";
    while (current != nullptr) {
        cout << current->e << " ";
        current = current->next;
    }
    cout << endl;

    return 0;
}