#include <bits/stdc++.h>
using namespace std;

int evaluatePostfix(string exp) {
    stack<int> stack;

    for (int i = 0; i < exp.length(); ++i) {
        if (isdigit(exp[i]))
            stack.push(exp[i] - '0');
        else {
            int a = stack.top();
            stack.pop();
            int b = stack.top();
            stack.pop();

            switch (exp[i]) {
                case '+':
                    stack.push(b + a);
                    break;
                case '-':
                    stack.push(b - a);
                    break;
                case '*':
                    stack.push(a * b);
                    break;
                case '/':
                    stack.push(b / a);
            }
        }
    }

    return stack.top();
}

int main() {
    string exp = "231*+9-";
    cout << evaluatePostfix(exp);

    return 0;
}