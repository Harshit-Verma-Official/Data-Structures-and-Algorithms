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

Node *getMiddle(Node *head) {
    Node *slow = head;
    Node *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

int main() {

    Node *head = nullptr;
    insertAtLast(head, 60);
    insertAtLast(head, 50);
    insertAtLast(head, 40);
    insertAtLast(head, 30);
    insertAtLast(head, 20);
    insertAtLast(head, 10);

    cout << getMiddle(head)->data;

    return 0;
}