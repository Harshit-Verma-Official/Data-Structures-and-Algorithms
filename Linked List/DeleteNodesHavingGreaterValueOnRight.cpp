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

Node *reverse(Node *head) {
    if (head == nullptr || head->next == nullptr)
        return head;

    Node *res = reverse(head->next);
    head->next->next = head;
    head->next = nullptr;
    return res;
}

void deleteNodesHavingGreaterValueOnRight(Node *&head) {
    head = reverse(head);
    Node *cur = head;
    Node *prev = head;
    head = head->next;
    int max = prev->data;
    while (head) {
        if (head->data >= prev->data) {
            max = head->data;
            head = head->next;
            prev = prev->next;
        } else {
            prev->next = head->next;
            delete head;
            head = prev->next;
        }
    }

    head = reverse(cur);
}

int main() {

    Node *head = nullptr;
    insertAtLast(head, 12);
    insertAtLast(head, 15);
    insertAtLast(head, 10);
    insertAtLast(head, 11);
    insertAtLast(head, 5);
    insertAtLast(head, 6);
    insertAtLast(head, 2);
    insertAtLast(head, 3);

    deleteNodesHavingGreaterValueOnRight(head);

    traverse(head);

    return 0;
}