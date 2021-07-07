#include <bits/stdc++.h>
using namespace std;

bool isOperator(char input) {
    switch (input) {
        case '+':
        case '-':
        case '*':
        case '/':
        case '^':
        case '(':
            return true;
    }
    return false;
}

bool isOperand(char input) {
    return (input >= 'a' and input <= 'z') or (input >= 'A' and input <= 'Z') or (input >= '0' and input <= '9');
}

int outPrec(char operand) {
    switch (operand) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
        case '%':
            return 3;
        case '^':
            return 6;
        case '(':
            return 100;
        default:
            return -1;
    }
}

int inPrec(char operand) {
    switch (operand) {
        case '+':
        case '-':
            return 2;
        case '*':
        case '/':
        case '%':
            return 4;
        case '^':
            return 5;
        case '(':
            return 0;
        default:
            return -1;
    }
}

string inToPost(string exp) {
    string res = "";
    stack<char> stack;

    for (int i = 0; i < exp.length(); ++i) {
        if (isOperand(exp[i]))
            res.push_back(exp[i]);
        else if (isOperator(exp[i])) {
            if (stack.empty() or outPrec(exp[i]) > inPrec(stack.top()))
                stack.push(exp[i]);
            else {
                while (!stack.empty() and outPrec(exp[i]) <= inPrec(stack.top())) {
                    res.push_back(stack.top());
                    stack.pop();
                }
                stack.push(exp[i]);
            }
        } else if (exp[i] == ')') {
            while (stack.top() != '(') {
                res.push_back(stack.top());
                stack.pop();
                if (stack.empty())
                    return "";
            }
            stack.pop();
        }
    }

    while (!stack.empty()) {
        res.push_back(stack.top());
        stack.pop();
    }

    return res;
}

int main() {
    string exp = "a+b*(c^d-e)^(f+g*h)-i";
    cout << inToPost(exp);
    return 0;
}