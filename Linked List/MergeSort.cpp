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
    while (fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

Node *sortedMerge(Node *head1, Node *head2) {
    if (head1 == nullptr)
        return head2;
    if (head2 == nullptr)
        return head1;

    Node *res = nullptr;
    if (head1->data <= head2->data) {
        res = head1;
        res->next = sortedMerge(head1->next, head2);
    } else {
        res = head2;
        res->next = sortedMerge(head1, head2->next);
    }

    return res;
}

Node *mergeSort(Node *head) {
    if (head == nullptr || head->next == nullptr)
        return head;

    Node *middle = getMiddle(head);
    Node *nextOfMiddle = middle->next;
    middle->next = nullptr;

    Node *left = mergeSort(head);
    Node *right = mergeSort(nextOfMiddle);

    return sortedMerge(left, right);
}

int main() {

    Node *head = nullptr;
    insertAtLast(head, 50);
    insertAtLast(head, 40);
    insertAtLast(head, 30);
    insertAtLast(head, 20);
    insertAtLast(head, 10);

    head = mergeSort(head);

    traverse(head);

    return 0;
}