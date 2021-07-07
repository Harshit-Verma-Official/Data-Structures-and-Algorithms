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

    Node *reverse(Node *node) {
        if (node == nullptr || node->next == nullptr)
            return node;

        Node *res = reverse(node->next);
        node->next->next = node;
        node->next = nullptr;
        return res;
    }

    int addOneRec(Node *node) {
        if (node == nullptr)
            return 1;

        int res = node->data + addOneRec(node->next);
        node->data = res % 10;
        return res / 10;
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

    void reverse() {
        head = reverse(head);
    }

    void addNumber(int n) {
        if (n == 0)
            return;

        addNumber(n / 10);
        insertAtLast(n % 10);
    }

    void addOne() {
        int c = 1;
        reverse();
        Node *current = head;
        while (current != nullptr && c != 0) {
            int sum = current->data + c;
            current->data = sum % 10;
            c = sum / 10;
            current = current->next;
        }
        if (c != 0)
            insertAtLast(c);
        reverse();
    }

    void addOneRec() {
        int carry = addOneRec(head);
        if (carry) {
            Node *node = new Node(carry);
            node->next = head;
            head = node;
        }
    }
};

int main() {

    LinkedList list;
    list.addNumber(999);
    list.addOneRec();
    list.traverse();

    return 0;
}