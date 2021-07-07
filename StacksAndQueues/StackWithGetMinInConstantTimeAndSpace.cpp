#include <bits/stdc++.h>
using namespace std;

class Stack {
   private:
    stack<int> stack;
    int minEle;

   public:
    void push(int x) {
        if (stack.empty()) {
            stack.push(x);
            minEle = x;
            return;
        }

        if (x < minEle) {
            stack.push(2 * x - minEle);
            minEle = x;
        } else
            stack.push(x);
    }

    int pop() {
        if (stack.empty())
            return -1;

        int top = stack.top();
        int res = top;
        stack.pop();

        if (top < minEle) {
            res = minEle;
            minEle = 2 * minEle - top;
        }

        return res;
    }

    int peek() {
        if (stack.empty())
            return -1;

        return stack.top() < minEle ? minEle : stack.top();
    }

    int getMin() {
        if (stack.empty())
            return -1;

        return minEle;
    }
};

int main() {
    return 0;
}