#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *next = nullptr;
    Node *prev = nullptr;
    Node(int data) {
        this->data = data;
    }
};

void traverse(Node *head) {
    Node *last = head;
    cout << "Traverse in forward direction : \n";
    while (head != nullptr) {
        cout << head->data << " ";
        last = head;
        head = head->next;
    }
    cout << "\nTraverse in backward direction : \n";
    while (last != nullptr) {
        cout << last->data << " ";
        last = last->prev;
    }
    cout << endl;
}

void sortedInsert(Node *&head, int data) {
    Node *node = new Node(data);

    if (head == nullptr || head->data >= data) {
        node->next = head;
        if (head != nullptr)
            head->prev = node;
        head = node;
        return;
    }

    Node *current = head;
    while (current->next != nullptr && current->next->data < data)
        current = current->next;

    node->next = current->next;
    node->prev = current;
    current->next = node;

    if (node->next != nullptr)
        node->next->prev = node;
}

int countPairs(Node *first, Node *second, int sum) {
    int count = 0;
    while (first != nullptr && second != nullptr && first != second && second->next != first) {
        if (first->data + second->data == sum) {
            count++;
            first = first->next;
            second = second->prev;
        } else {
            if (first->data + second->data < sum)
                first = first->next;
            else
                second = second->prev;
        }
    }
    return count;
}

int countTriplets(Node *head, int sum) {
    int count = 0;
    Node *first = head;
    Node *second = head;
    while (second->next != nullptr)
        second = second->next;

    while (head != nullptr) {
        first = head->next;
        count += countPairs(first, second, sum - head->data);
        head = head->next;
    }

    return count;
}

int main() {

    Node *head = nullptr;
    sortedInsert(head, 1);
    sortedInsert(head, 2);
    sortedInsert(head, 4);
    sortedInsert(head, 5);
    sortedInsert(head, 6);
    sortedInsert(head, 8);
    sortedInsert(head, 9);

    cout << countTriplets(head, 17);

    return 0;
}