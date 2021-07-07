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

int main() {
    stack<int> s;

    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

    insertAtBottom(s, 0);

    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }

    return 0;
}