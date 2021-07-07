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

void sortedInsert(Node *&head, int data) {
    Node *node = new Node(data);

    if (head == nullptr || head->data >= data) {
        node->next = head;
        head = node;
        return;
    }

    Node *current = head;
    while (current->next->data < data)
        current = current->next;

    node->next = current->next;
    current->next = node;
}

void traverse(Node *head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
}

int getLength(Node *head) {
    int count = 0;
    while (head != nullptr) {
        count++;
        head = head->next;
    }
    return count;
}

int getIntersection(Node *head1, Node *head2) {
    int m = getLength(head1);
    int n = getLength(head2);
    int d = m > n ? (m - n) : (n - m);

    if (m > n)
        while (d--)
            head1 = head1->next;
    else
        while (d--)
            head2 = head2->next;

    while (head1 && head2) {
        if (head1 == head2)
            return head1->data;
        head1 = head1->next;
        head2 = head2->next;
    }

    return -1;
}

int main() {

    Node *head = nullptr;
    sortedInsert(head, 40);
    sortedInsert(head, 30);
    sortedInsert(head, 20);
    sortedInsert(head, 10);

    Node *head2 = nullptr;
    sortedInsert(head2, 40);
    sortedInsert(head2, 30);
    head2->next->next = head->next->next;

    cout << getIntersection(head, head2);

    return 0;
}