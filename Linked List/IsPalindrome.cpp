#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *next = nullptr;
    Node(int data) {
        this->data = data;
    }
};

void insertAtLast(Node *&head, int data) {
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

void traverse(Node *head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
}

Node *reverse(Node *head) {
    if (head == nullptr || head->next == nullptr)
        return head;

    Node *res = reverse(head->next);
    head->next->next = head;
    head->next = nullptr;
    return res;
}

bool isPalindrome(Node *head) {
    Node *slow = head;
    Node *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    Node *cur = reverse(slow);
    fast = head;
    while (cur != nullptr) {
        if (fast->data != cur->data)
            return false;

        fast = fast->next;
        cur = cur->next;
    }

    return true;
}

int main() {

    Node *head = nullptr;
    insertAtLast(head, 1);

    cout << isPalindrome(head);

    return 0;
}