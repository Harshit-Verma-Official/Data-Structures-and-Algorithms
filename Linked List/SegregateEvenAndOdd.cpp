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

void segregateEvenOdd(Node *&head) {
    Node *current = head;
    Node *even = nullptr;
    Node *odd = nullptr;
    Node *e = nullptr;
    Node *o = nullptr;
    while (current) {
        if (current->data % 2 == 0) {
            if (even == nullptr) {
                even = current;
                e = current;
            } else {
                e->next = current;
                e = e->next;
            }
        } else {
            if (odd == nullptr) {
                odd = current;
                o = current;
            } else {
                o->next = current;
                o = o->next;
            }
        }
        current = current->next;
    }

    if (e)
        e->next = odd;
    if (o)
        o->next = nullptr;
    if (even)
        head = even;
    else
        head = odd;
}

int main() {

    Node *head = nullptr;
    insertAtLast(head, 17);
    insertAtLast(head, 15);
    insertAtLast(head, 8);
    insertAtLast(head, 9);
    insertAtLast(head, 2);
    insertAtLast(head, 4);
    insertAtLast(head, 6);

    segregateEvenOdd(head);

    traverse(head);

    return 0;
}