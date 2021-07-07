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

    Node *reverseRec(Node *node) {
        if (node == nullptr || node->next == nullptr)
            return node;

        Node *res = reverseRec(node->next);
        node->next->next = node;
        node->next = nullptr;
        return res;
    }

public:
    void traverse() {
        Node *current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
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

    void reverseRec() {
        head = reverseRec(head);
    }

    void reverseItr() {
        if (head == nullptr || head->next == nullptr)
            return;

        Node *current = head;
        Node *prev = nullptr;
        while (current != nullptr) {
            Node *next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }

        head = prev;
    }
};

int main() {

    LinkedList list;
    list.insertAtLast(10);
    list.insertAtLast(20);
    list.insertAtLast(30);
    list.insertAtLast(40);
    list.insertAtLast(50);
    list.reverseItr();
    list.traverse();

    return 0;
}