#include <bits/stdc++.h>
using namespace std;

bool hasDuplicates(string exp) {
    stack<char> stack;

    for (int i = 0; i < exp.length(); ++i) {
        char ch = exp[i];
        if (ch == ')') {
            if (stack.top() == '(')
                return true;
            while (stack.top() != '(')
                stack.pop();
            stack.pop();
        } else
            stack.push(ch);
    }

    return false;
}

int main() {
    string str = "((a+b))";

    if (hasDuplicates(str))
        cout << "Duplicate Found ";
    else
        cout << "No Duplicates Found ";

    return 0;
}