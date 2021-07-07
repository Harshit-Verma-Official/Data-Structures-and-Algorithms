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

void rotate(Node *&head, int n) {
    if (n == 0)
        return;

    Node *current = head;
    int count = 1;
    while (count < n && current != nullptr) {
        count++;
        current = current->next;
    }

    Node *nthNode = current;
    while (current->next != nullptr)
        current = current->next;

    current->next = head;
    head->prev = current;

    head = nthNode->next;
    head->prev = nullptr;
    nthNode->next = nullptr;
}

int main() {

    Node *head = nullptr;
    insertAtLast(head, 10);
    insertAtLast(head, 20);
    insertAtLast(head, 30);
    insertAtLast(head, 40);
    insertAtLast(head, 50);

    rotate(head, 4);

    traverse(head);

    return 0;
}