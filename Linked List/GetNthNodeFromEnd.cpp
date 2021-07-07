#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *next = nullptr;
    Node(int data) {
        this->data = data;
    }
};

void insertAtLast(Node *&head, int data) {
    Node *node = new Node(data);

    if (head == nullptr) {
        head = node;
        return;
    }

    Node *current = head;
    while (current->next != nullptr)
        current = current->next;

    current->next = node;
}

void traverse(Node *head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
}

int getNthFromLast(Node *head, int n) {
    Node *p = head;
    Node *q = head;
    for (int i = 0; i < n - 1; ++i) {
        q = q->next;
        if (q == nullptr)
            return -1;
    }

    while (q->next != nullptr) {
        p = p->next;
        q = q->next;
    }

    if (p)
        return p->data;
    return -1;
}

int main() {

    Node *head = nullptr;
    insertAtLast(head, 50);
    insertAtLast(head, 40);
    insertAtLast(head, 30);
    insertAtLast(head, 20);
    insertAtLast(head, 10);

    traverse(head);
    cout << endl
         << getNthFromLast(head, 4);

    return 0;
}