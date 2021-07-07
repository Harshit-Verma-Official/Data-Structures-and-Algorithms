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

long long multiplyTwoLists(Node *l1, Node *l2) {
    long long a = 0, b = 0, mod = 1000000007;
    while (l1 || l2) {
        if (l1) {
            a = (a % mod * 10 % mod) % mod + l1->data % mod;
            l1 = l1->next;
        }
        if (l2) {
            b = (b % mod * 10 % mod) % mod + l2->data % mod;
            l2 = l2->next;
        }
    }
    return (a % mod * b % mod) % mod;
}

int main() {

    Node *head = nullptr;
    insertAtLast(head, 2);
    insertAtLast(head, 2);
    insertAtLast(head, 2);

    Node *head2 = nullptr;
    insertAtLast(head2, 2);

    cout << multiplyTwoLists(head, head2);

    return 0;
}