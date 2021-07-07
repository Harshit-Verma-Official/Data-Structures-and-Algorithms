// Given two arrays, check if one array is
// stack permutation of other.
#include<bits/stdc++.h>
using namespace std;
  
bool checkStackPermutation(int ip[], int op[], int n) {
    queue<int> input;
    queue<int> output;
    stack<int> stack;

    for (int i = 0; i < n; ++i) {
        input.push(ip[i]);
        output.push(op[i]);
    }

    
    while (!input.empty()) {
        stack.push(input.front());
        input.pop();

        while (!stack.empty() and stack.top() == output.front()) {
            stack.pop();
            output.pop();
        }
    }

    return input.empty() and stack.empty();
}
  
int main()
{
    int input[] = {1, 2, 3};
  
    int output[] = {2, 1, 3};
  
    int n = 3;
  
    if (checkStackPermutation(input, output, n))
        cout << "Yes";
    else
        cout << "Not Possible";
    return 0;
}