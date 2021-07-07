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

    void sortedInsert(int data) {
        Node *node = new Node(data);

        if (head == nullptr || head->data >= data) {
            node->next = head;
            head = node;
            return;
        }

        Node *current = head;
        while (current->next->data < data)
            current = current->next;

        node->next = current->next;
        current->next = node;
    }

    void removeDuplicates() {
        Node *current = head;
        while (current->next != nullptr) {
            Node *next = current->next;
            if (current->data == next->data) {
                current->next = next->next;
                delete next;
            } else
                current = current->next;
        }
    }
};

int main() {

    LinkedList list;
    list.sortedInsert(50);
    list.sortedInsert(50);
    list.sortedInsert(50);
    list.sortedInsert(40);
    list.sortedInsert(40);
    list.sortedInsert(30);
    list.sortedInsert(30);
    list.sortedInsert(20);
    list.sortedInsert(20);
    list.sortedInsert(10);
    list.sortedInsert(10);
    list.sortedInsert(10);

    list.removeDuplicates();

    list.traverse();

    return 0;
}