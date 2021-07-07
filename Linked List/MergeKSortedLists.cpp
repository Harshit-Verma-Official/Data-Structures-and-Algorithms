#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *next = NULL;
    Node(int data) {
        this->data = data;
    }
};

Node *merge(Node *a, Node *b) {
    if (a == NULL)
        return b;
    if (b == NULL)
        return a;

    Node *res = NULL;
    if (a->data <= b->data) {
        res = a;
        res->next = merge(a->next, b);
    } else {
        res = b;
        res->next = merge(a, b->next);
    }

    return res;
}
//Function to merge K sorted linked list.
Node *mergeKLists(Node *arr[], int K) {
    int i = 0;
    int last = K - 1;
    int j;
    while (last != 0) {
        i = 0;
        j = last;
        while (i < j) {
            arr[i] = merge(arr[i], arr[j]);
            i++;
            j--;
            if (i >= j)
                last = j;
        }
    }
    return arr[0];
}