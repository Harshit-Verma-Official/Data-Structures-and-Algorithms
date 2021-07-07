#include <bits/stdc++.h>
using namespace std;

void insertAtBottom(stack<int> &s, int key) {
    if (s.empty()) {
        s.push(key);
        return;
    }

    int top = s.top();
    s.pop();
    insertAtBottom(s, key);

    s.push(top);
}

void reverseStack(stack<int> &s) {
    if (s.empty())
        return;

    int top = s.top();
    s.pop();

    reverseStack(s);

    insertAtBottom(s, top);
}

int main() {
    stack<int> s;

    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);

    reverseStack(s);

    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }

    return 0;
}