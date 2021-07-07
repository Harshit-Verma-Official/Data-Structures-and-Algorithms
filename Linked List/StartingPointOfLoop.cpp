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

    void makeLoop() {
        head->next->next->next->next->next = head->next->next;
    }

    Node *getStartLoopNode() {
        Node *slow = head;
        Node *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
                break;
        }
        slow = head;
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};

int main() {

    LinkedList list;
    list.insertAtLast(10);
    list.insertAtLast(20);
    list.insertAtLast(30);
    list.insertAtLast(40);
    list.insertAtLast(50);

    list.makeLoop();
    cout << list.getStartLoopNode()->data;

    return 0;
}