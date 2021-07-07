// C++ program for an efficient solution to check if
// a given array can represent Preorder traversal of
// a Binary Search Tree
#include <bits/stdc++.h>
using namespace std;

bool canRepresentBST(int pre[], int n) {
    stack<int> stack;
    int root = INT_MIN;

    for (int i = 0; i < n; ++i) {
        if (pre[i] < root)
            return false;

        while (!stack.empty() and pre[i] > stack.top()) {
            root = stack.top();
            stack.pop();
        }

        stack.push(pre[i]);
    }

    return true;
}

// Driver program
int main() {
    int pre1[] = {40, 30, 35, 80, 100};
    int n = sizeof(pre1) / sizeof(pre1[0]);
    canRepresentBST(pre1, n) ? cout << "true\n" : cout << "false\n";

    int pre2[] = {40, 30, 35, 20, 80, 100};
    n = sizeof(pre2) / sizeof(pre2[0]);
    canRepresentBST(pre2, n) ? cout << "true\n" : cout << "false\n";

    return 0;
}