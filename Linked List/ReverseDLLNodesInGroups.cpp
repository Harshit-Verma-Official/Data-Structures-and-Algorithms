#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *next = nullptr;
    Node *prev = nullptr;
    Node(int data) {
        this->data = data;
    }
};

void traverse(Node *head) {
    Node *last = nullptr;
    cout << "Forward Traverse : \n";
    while (head != nullptr) {
        cout << head->data << " ";
        last = head;
        head = head->next;
    }
    cout << "\nBackward Traverse : \n";
    while (last != nullptr) {
        cout << last->data << " ";
        last = last->prev;
    }
    cout << endl;
}

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
    node->prev = current;
}

Node *reverseByKNodes(Node *head, int k) {
    Node *current = head;
    Node *prev = nullptr;
    Node *next = nullptr;
    int count = 0;
    while (current != nullptr && count < k) {
        next = current->next;
        current->next = prev;
        current->prev = next;
        prev = current;
        current = next;
        count++;
    }

    if (next != nullptr) {
        head->next = reverseByKNodes(next, k);
        head->next->prev = head;
    }

    prev->prev = nullptr;
    return prev;
}

void reverse(Node *&head) {
    Node *current = head;
    Node *prev = nullptr;
    while (current != nullptr) {
        Node *next = current->next;
        current->next = prev;
        current->prev = next;
        prev = current;
        current = next;
    }
    head = prev;
}

int main() {

    Node *head = nullptr;
    insertAtLast(head, 10);
    insertAtLast(head, 20);
    insertAtLast(head, 30);
    insertAtLast(head, 40);
    insertAtLast(head, 50);

    head = reverseByKNodes(head, 3);
    traverse(head);

    return 0;
}