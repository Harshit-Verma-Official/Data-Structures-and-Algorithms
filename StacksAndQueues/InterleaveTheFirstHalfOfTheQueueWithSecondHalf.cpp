// C++ program to interleave the first half of the queue
// with the second half
#include <bits/stdc++.h>
using namespace std;
  
// Function to interleave the queue
void interLeaveQueue(queue<int>& q) {
    int n = q.size();
    stack<int> stack;

    for (int i = 0; i < n / 2; ++i) {
        stack.push(q.front());
        q.pop();
    }

    while (!stack.empty()) {
        q.push(stack.top());
        stack.pop();
    }

    for (int i = 0; i < n / 2; ++i) {
        q.push(q.front());
        q.pop();
    }

    for (int i = 0; i < n / 2; ++i) {
        stack.push(q.front());
        q.pop();
    }

    while (!stack.empty()) {
        q.push(stack.top());
        q.push(q.front());
        stack.pop();
        q.pop();
    }

}
  
int main()
{
    queue<int> q;
    q.push(11);
    q.push(12);
    q.push(13);
    q.push(14);
    q.push(15);
    q.push(16);
    q.push(17);
    q.push(18);
    q.push(19);
    q.push(20);
    interLeaveQueue(q);
    int length = q.size();
    for (int i = 0; i < length; i++) {
        cout << q.front() << " ";
        q.pop();
    }
    return 0;
}