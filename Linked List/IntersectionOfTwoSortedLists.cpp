#include <bits/stdc++.h>
using namespace std;

class LinkedList {
private:
    class Node {
    public:
        int data;
        Node *next = nullptr;
        Node(int data) {
            this->data = data;
        }
    };
    Node *head = nullptr;

    Node *getIntersection(Node *p, Node *q) {
        if (p == nullptr || q == nullptr)
            return nullptr;

        if (p->data < q->data)
            return getIntersection(p->next, q);
        if (q->data < p->data)
            return getIntersection(p, q->next);

        Node *node = new Node(p->data);
        node->next = getIntersection(p->next, q->next);
        return node;
    }

public:
    void traverse() {
        Node *current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
    }

    void traverse(Node *node) {
        while (node != nullptr) {
            cout << node->data << " ";
            node = node->next;
        }
    }

    void insertAtLast(int data) {
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

    Node *getIntersection(LinkedList list) {
        Node *p = head;
        Node *q = list.head;
        Node *res = new Node(0);
        Node *temp = res;
        while (p != nullptr && q != nullptr) {
            if (p->data == q->data) {
                Node *node = new Node(p->data);
                temp->next = node;
                temp = temp->next;
                p = p->next;
                q = q->next;
            } else if (p->data < q->data)
                p = p->next;
            else
                q = q->next;
        }
        return res->next;
    }

    void getIntersectionRec(LinkedList list) {
        traverse(getIntersection(head, list.head));
    }
};

int main() {

    LinkedList list;
    list.insertAtLast(1);
    list.insertAtLast(2);
    list.insertAtLast(3);
    list.insertAtLast(4);
    list.insertAtLast(5);
    // list.traverse();

    LinkedList list2;
    list2.insertAtLast(2);
    list2.insertAtLast(4);
    list2.insertAtLast(6);
    list2.insertAtLast(8);

    list.getIntersectionRec(list2);

    return 0;
}