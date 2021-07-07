#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *next = nullptr;
    Node() {}
    Node(int data) {
        this->data = data;
    }
};

void push(Node *&head, int data) {
    Node *node = new Node(data);
    node->next = head;
    head = node;
}

void printList(Node *head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int getLength(Node *head) {
    int count = 0;
    while (head != nullptr) {
        count++;
        head = head->next;
    }
    return count;
}

void swapNodes(Node *&a, Node *&b) {
    Node *temp = a;
    a = b;
    b = temp;
}

Node *addSameSizeLists(Node *head1, Node *head2, int *carry) {
    if (head1 == nullptr)
        return nullptr;

    Node *res = new Node();
    res->next = addSameSizeLists(head1->next, head2->next, carry);

    int sum = head1->data + head2->data + *carry;
    *carry = sum / 10;
    sum %= 10;

    res->data = sum;

    return res;
}

void addToRemaining(Node *head, Node *cur, int *carry, Node *&res) {
    if (head != cur) {
        addToRemaining(head->next, cur, carry, res);

        int sum = head->data + *carry;
        *carry = sum / 10;
        sum %= 10;

        push(res, sum);
    }
}

void addLists(Node *head1, Node *head2, Node *&res) {
    if (head1 == nullptr) {
        res = head2;
        return;
    }
    if (head2 == nullptr) {
        res = head1;
        return;
    }

    int size1 = getLength(head1);
    int size2 = getLength(head2);
    int carry = 0;
    if (size1 == size2)
        res = addSameSizeLists(head1, head2, &carry);
    else {
        if (size1 < size2)
            swap(head1, head2);

        int diff = abs(size1 - size2);
        Node *cur;
        for (cur = head1; diff--; cur = cur->next)
            ;

        res = addSameSizeLists(cur, head2, &carry);
        addToRemaining(head1, cur, &carry, res);
    }

    if (carry)
        push(res, carry);
}

int main() {

    Node *head1 = nullptr;
    Node *head2 = nullptr;
    Node *res = nullptr;

    int a[] = {9, 9, 9};
    int b[] = {1, 8};

    int m = sizeof(a) / sizeof(a[0]);
    int n = sizeof(b) / sizeof(b[0]);

    for (int i = m - 1; i >= 0; --i)
        push(head1, a[i]);
    for (int i = n - 1; i >= 0; --i)
        push(head2, b[i]);

    printList(head1);
    printList(head2);

    addLists(head1, head2, res);
    printList(res);

    return 0;
}