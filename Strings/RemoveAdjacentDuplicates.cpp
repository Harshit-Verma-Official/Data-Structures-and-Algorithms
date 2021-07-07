#include <bits/stdc++.h>
using namespace std;

string removeAdjacentDuplicates(string str) {
    stack<char> stack;
    for (int i = 0; i < str.length(); ++i) {
        if (stack.empty())
            stack.push(str[i]);
        else if (stack.top() == str[i])
            stack.pop();
        else
            stack.push(str[i]);
    }

    string res = "";
    while (!stack.empty()) {
        res.push_back(stack.top());
        stack.pop();
    }

    reverse(res.begin(), res.end());

    return res;
}

int main() {
    string str = "azxxzy";

    cout << removeAdjacentDuplicates(str);

    return 0;
}