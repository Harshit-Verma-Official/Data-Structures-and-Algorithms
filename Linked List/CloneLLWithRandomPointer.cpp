#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *next = NULL;
    Node *arb = NULL;
    Node(int data) {
        this->data = data;
    }
};

Node *copyList(Node *head) {
    Node *current = head;
    while (current != NULL) {
        Node *next = current->next;
        current->next = new Node(current->data);
        current->next->next = next;
        current = next;
    }

    current = head;
    while (current) {
        current->next->arb = current->arb ? current->arb->next : current->arb;
        current = current->next->next;
    }

    current = head;
    Node *copy = head->next;
    Node *temp = copy;
    while (current and copy) {
        current->next = current->next->next;
        copy->next = copy->next ? copy->next->next : copy->next;
        current = current->next;
        copy = copy->next;
    }

    return temp;
}

int main() {

    return 0;
}