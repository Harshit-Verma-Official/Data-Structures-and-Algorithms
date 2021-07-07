#include <bits/stdc++.h>
using namespace std;

bool hasRedundancy(string &str) {
    stack<char> stack;

    for (int i = 0; i < str.length(); ++i) {
        char ch = str[i];

        if (ch == ')') {
            if (stack.top() == '(')
                return true;
            bool flag = true;
            while (stack.top() != '(') {
                if (stack.top() == '+' or stack.top() == '-' or stack.top() == '*' or stack.top() == '/')
                    flag = false;
                stack.pop();
            }
            stack.pop();
            if (flag)
                return true;
        } else
            stack.push(ch);
    }

    return false;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        string str;
        cin >> str;
        hasRedundancy(str) ? cout << "Yes\n" : cout << "No\n";
    }

    return 0;
}