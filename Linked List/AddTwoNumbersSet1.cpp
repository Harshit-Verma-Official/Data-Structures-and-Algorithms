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

    void reverse() {
        head = reverse(head);
    }

    void insertNumber(int n) {
        if (n == 0)
            return;

        insertAtLast(n % 10);
        insertNumber(n / 10);
    }

    // Head contains least significant digits

    Node *addNumbers(LinkedList list) {
        Node *newNode = new Node(0);
        Node *temp = newNode;
        Node *l1 = head;
        Node *l2 = list.head;
        int sum = 0;
        int carry = 0;
        while (l1 != nullptr || l2 != nullptr || carry == 1) {
            sum = 0;
            if (l1 != nullptr) {
                sum += l1->data;
                l1 = l1->next;
            }
            if (l2 != nullptr) {
                sum += l2->data;
                l2 = l2->next;
            }
            sum += carry;
            carry = sum / 10;
            Node *node = new Node(sum % 10);
            temp->next = node;
            temp = temp->next;
        }
        return newNode->next;
    }
};

int main() {

    LinkedList list;
    list.insertNumber(365);
    // list.traverse();
    LinkedList list2;
    list2.insertNumber(248);
    // list2.traverse();
    list.traverse(list.addNumbers(list2));

    return 0;
}