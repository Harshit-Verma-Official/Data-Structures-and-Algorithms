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

void sort(Node *head) {
    int counts[] = {0, 0, 0};
    Node *current = head;
    while (current != nullptr) {
        counts[current->data]++;
        current = current->next;
    }

    int i = 0;
    current = head;
    while (current != nullptr) {
        if (counts[i] == 0)
            i++;
        current->data = i;
        --counts[i];
        current = current->next;
    }
}

int main() {

    Node *head = nullptr;
    insertAtLast(head, 2);
    insertAtLast(head, 1);
    insertAtLast(head, 0);
    insertAtLast(head, 2);
    insertAtLast(head, 1);
    insertAtLast(head, 1);
    insertAtLast(head, 0);
    insertAtLast(head, 0);

    sort(head);

    traverse(head);

    return 0;
}