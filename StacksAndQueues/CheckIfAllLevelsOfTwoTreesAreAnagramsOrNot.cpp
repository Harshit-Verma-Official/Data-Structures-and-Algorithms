/* Iterative program to check if two trees are level
   by level anagram. */
#include <bits/stdc++.h>
using namespace std;
  
struct Node {
    struct Node *left, *right;
    int data;
};
  
bool areAnagrams(Node *root1, Node *root2) {
    if (!root1 and !root2)
        return true;
    if (!root1 or !root2)
        return false;

    queue<Node *> q1;
    queue<Node *> q2;

    q1.push(root1);
    q2.push(root2);

    while (true) {
        int n1 = q1.size();
        int n2 = q2.size();

        if (n1 != n2)
            return false;

        if (n1 == 0)
            break;

        set<int> s;

        while (n1--) {
            Node *c1 = q1.front();
            s.insert(c1->data);
            q1.pop();
            if (c1->left)
                q1.push(c1->left);
            if (c1->right)
                q1.push(c1->right);
        }

        while (n2--) {
            Node *c2 = q2.front();
            if (s.find(c2->data) == s.end())
                return false;
            q2.pop();
            if (c2->left)
                q2.push(c2->left);
            if (c2->right)
                q2.push(c2->right);
        }
    }

    return true;
}
  
Node* newNode(int data) {
    Node *temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}
  
int main() {
    // Constructing both the trees.
    struct Node* root1 = newNode(1);
    root1->left = newNode(3);
    root1->right = newNode(2);
    root1->right->left = newNode(5);
    root1->right->right = newNode(4);
  
    struct Node* root2 = newNode(1);
    root2->left = newNode(2);
    root2->right = newNode(3);
    root2->left->left = newNode(4);
    root2->left->right = newNode(5);
  
    areAnagrams(root1, root2)? cout << "Yes" : cout << "No";
    return 0;
}