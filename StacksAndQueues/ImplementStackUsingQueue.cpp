#include <bits/stdc++.h>
using namespace std;

// Costly Push Operation
template <class T>
class Stack_Costly_Push {
   private:
    queue<T> q1;
    queue<T> q2;

   public:
    void push(T val) {
        q2.push(val);

        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }

        swap(q1, q2);
    }

    T pop() {
        if (isEmpty())
            return -1;

        T res = q1.front();
        q1.pop();

        return res;
    }

    bool isEmpty() {
        return q1.empty();
    }
};

template <class T>
class Stack_Costly_Pop {
   private:
    queue<T> q1;
    queue<T> q2;

   public:
    void push(T val) {
        q1.push(val);
    }

    T pop() {
        if (isEmpty())
            return -1;

        while (q1.size() != 1) {
            q2.push(q1.front());
            q1.pop();
        }

        T res = q1.front();
        q1.pop();

        swap(q1, q2);

        return res;
    }

    bool isEmpty() {
        return q1.empty();
    }
};

int main() {
    Stack_Costly_Pop<int> stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    stack.push(5);

    while (!stack.isEmpty())
        cout << stack.pop() << " ";

    return 0;
}