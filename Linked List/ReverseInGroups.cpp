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

    Node *reverseInGroups(Node *node, int k) {
        Node *current = node;
        Node *prev = nullptr;
        Node *next = nullptr;
        int count = 0;
        while (current != nullptr && count < k) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
            count++;
        }

        if (next != nullptr)
            node->next = reverseInGroups(next, k);

        return prev;
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

    void reverseInGroups(int k) {
        head = reverseInGroups(head, k);
    }
};

int main() {

    LinkedList list;
    list.insertAtLast(10);
    list.insertAtLast(20);
    list.insertAtLast(30);
    list.insertAtLast(40);
    list.insertAtLast(50);
    list.reverseInGroups(3);
    list.traverse();

    return 0;
}