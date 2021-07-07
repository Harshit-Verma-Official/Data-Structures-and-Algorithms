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
    Node *current = head;
    do {
        cout << current->data << " ";
        current = current->next;
    } while (current != head);
}

void makeCircular(Node *head) {
    Node *current = head;
    while (current->next != nullptr)
        current = current->next;
    current->next = head;
}

bool isCircular(Node *head) {
    if (head == nullptr)
        return true;

    Node *current = head->next;
    while (current != head && current != nullptr)
        current = current->next;

    return current == head;
}

int main() {

    Node *head = nullptr;
    insertAtLast(head, 50);
    insertAtLast(head, 40);
    insertAtLast(head, 30);
    insertAtLast(head, 20);
    insertAtLast(head, 10);

    makeCircular(head);
    cout << isCircular(head);

    return 0;
}