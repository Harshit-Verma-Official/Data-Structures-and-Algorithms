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

void split(Node *head, Node **head1_ref, Node **head2_ref) {
    Node *slow = head;
    Node *fast = head->next;
    while (fast != head && fast->next != head) {
        slow = slow->next;
        fast = fast->next->next;
    }
    *head1_ref = head;
    *head2_ref = slow->next;
    slow->next = *head1_ref;

    Node *cur = *head2_ref;
    while (cur->next != head)
        cur = cur->next;
    cur->next = *head2_ref;
}

int main() {

    Node *head = nullptr;
    insertAtLast(head, 50);
    insertAtLast(head, 40);
    insertAtLast(head, 30);
    insertAtLast(head, 20);
    insertAtLast(head, 10);
    makeCircular(head);

    Node *h1 = nullptr;
    Node *h2 = nullptr;
    split(head, &h1, &h2);

    traverse(h1);
    cout << endl;
    traverse(h2);

    return 0;
}