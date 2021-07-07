#include <bits/stdc++.h>
using namespace std;

void sortedInsert(stack<int> &s, int key) {
    if (s.empty() or key > s.top())
        s.push(key);
    else {
        int top = s.top();
        s.pop();
        sortedInsert(s, key);
        s.push(top);
    }
}

void sortStack(stack<int> &s) {
    if (s.empty())
        return;

    int top = s.top();
    s.pop();
    sortStack(s);
    sortedInsert(s, top);
}

int main() {
    stack<int> s;

    s.push(5);
    s.push(0);
    s.push(4);
    s.push(7);
    s.push(1);

    sortStack(s);

    while (!s.empty()) {
        cout << s.top() << endl;
        s.pop();
    }

    return 0;
}