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

    void removeDuplicates() {
        unordered_set<int> seen;
        Node *current = head;
        Node *prev = nullptr;
        while (current != nullptr) {
            if (seen.find(current->data) != seen.end()) {
                prev->next = current->next;
                delete current;
            } else {
                seen.insert(current->data);
                prev = current;
            }
            current = prev->next;
        }
    }

    void removeDuplicatesLooping() {
        Node *ptr1 = head;
        Node *ptr2;
        while (ptr1 && ptr1->next) {
            ptr2 = ptr1;
            while (ptr2->next != nullptr) {
                if (ptr1->data == ptr2->next->data) {
                    Node *next = ptr2->next;
                    ptr2->next = next->next;
                    delete next;
                } else
                    ptr2 = ptr2->next;
            }
            ptr1 = ptr1->next;
        }
    }
};

int main() {

    LinkedList list;
    list.insertAtLast(20);
    list.insertAtLast(10);
    list.insertAtLast(20);
    list.insertAtLast(50);
    list.insertAtLast(40);
    list.insertAtLast(50);
    list.insertAtLast(20);
    list.insertAtLast(30);
    list.insertAtLast(50);

    list.removeDuplicatesLooping();

    list.traverse();

    return 0;
}