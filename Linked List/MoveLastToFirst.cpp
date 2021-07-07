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

    void moveToFirst() {
        if (head == nullptr || head->next == nullptr)
            return;

        Node *current = head;
        Node *prev = nullptr;
        while (current->next != nullptr) {
            prev = current;
            current = current->next;
        }
        prev->next = nullptr;
        current->next = head;
        head = current;
    }
};

int main() {

    LinkedList list;
    list.insertAtLast(10);
    list.insertAtLast(20);
    // list.insertAtLast(30);
    // list.insertAtLast(40);
    // list.insertAtLast(50);

    list.moveToFirst();
    list.moveToFirst();

    list.traverse();

    return 0;
}