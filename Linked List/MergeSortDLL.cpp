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
    Node *last = head;
    cout << "Traverse in forward direction : \n";
    while (head != nullptr) {
        cout << head->data << " ";
        last = head;
        head = head->next;
    }
    cout << "\nTraverse in backward direction : \n";
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
        res->next->prev = res;
        res->prev = nullptr;
    } else {
        res = head2;
        res->next = sortedMerge(head1, head2->next);
        res->next->prev = res;
        res->prev = nullptr;
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

void countPairs(Node *head, int sum) {
    Node *p = head;
    Node *q = head;
    while (q->next != nullptr)
        q = q->next;

    while (p != nullptr && q != nullptr && p != q && q->next != p) {
        if (p->data + q->data == sum) {
            cout << "(" << p->data << ", " << q->data << ")" << endl;
            p = p->next;
            q = q->next;
        } else {
            if (p->data + q->data < sum)
                p = p->next;
            else
                q = q->prev;
        }
    }
}

int main() {

    Node *head = nullptr;
    insertAtLast(head, 9);
    insertAtLast(head, 8);
    insertAtLast(head, 6);
    insertAtLast(head, 5);
    insertAtLast(head, 4);
    insertAtLast(head, 2);
    insertAtLast(head, 1);

    head = mergeSort(head);

    countPairs(head, 7);

    return 0;
}