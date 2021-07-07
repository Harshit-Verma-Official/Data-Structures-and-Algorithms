/* C++ program to find the median of BST in O(n)
   time and O(1) space*/
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node *newNode(int item) {
    struct Node *temp = new Node;
    temp->data = item;
    temp->left = temp->right = NULL;
    return temp;
}

struct Node *insert(struct Node *node, int key) {
    if (node == NULL) return newNode(key);

    if (key < node->data)
        node->left = insert(node->left, key);
    else if (key > node->data)
        node->right = insert(node->right, key);

    return node;
}

int countNodes(struct Node *root) {
    int count = 0;

    if (!root)
        return count;

    Node *current = root;

    while (current) {
        if (!current->left) {
            count++;
            current = current->right;
        } else {
            Node *pre = current->left;
            while (pre->right and pre->right != current)
                pre = pre->right;

            if (!pre->right) {
                pre->right = current;
                current = current->left;
            } else {
                pre->right = NULL;
                count++;
                current = current->right;
            }
        }
    }

    return count;
}

int findMedian(struct Node *root) {
    if (!root)
        return 0;

    int count = countNodes(root);
    int currentCount = 0;

    Node *current = root;
    Node *prev = NULL;

    while (current) {
        if (!current->left) {
            currentCount++;

            if (count % 2 != 0 and currentCount == (count + 1) / 2)
                return prev->data;
            else if (count % 2 == 0 and currentCount == (count / 2 + 1))
                return (prev->data + current->data) / 2;

            prev = current;
            current = current->right;
        } else {
            Node *pre = current->left;
            while (pre->right and pre->right != current)
                pre = pre->right;

            if (!pre->right) {
                pre->right = current;
                current = current->left;
            } else {
                pre->right = NULL;

                prev = pre;

                currentCount++;

                if (count % 2 != 0 and currentCount == (count + 1) / 2)
                    return current->data;
                else if (count % 2 == 0 and currentCount == (count / 2 + 1))
                    return (prev->data + current->data) / 2;

                prev = current;
                current = current->right;
            }
        }
    }

    return 0;
}

int main() {
    /* Create following BST
                  50
               /     \
              30      70
             /  \    /  \
           20   40  60   80 */
    struct Node *root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    cout << "\nMedian of BST is "
         << findMedian(root);
    return 0;
}