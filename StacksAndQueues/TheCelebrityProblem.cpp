#include <bits/stdc++.h>

#include <list>
using namespace std;

#define N 8

bool MATRIX[N][N] = {{0, 0, 1, 0},
                     {0, 0, 1, 0},
                     {0, 0, 0, 0},
                     {0, 0, 1, 0}};

bool knows(int a, int b) {
    return MATRIX[a][b];
}

int findCelebrity(int n) {
    stack<int> stack;

    for (int i = 0; i < n; ++i)
        stack.push(i);

    while (stack.size() >= 2) {
        int i = stack.top();
        stack.pop();
        int j = stack.top();
        stack.pop();

        knows(i, j) ? stack.push(j) : stack.push(i);
    }

    int pot = stack.top();
    for (int i = 0; i < n; ++i)
        if (i != pot)
            if (knows(i, pot) == 0 or knows(pot, i) == 1)
                return -1;

    return pot;
}

// Driver code
int main() {
    int n = 4;
    int id = findCelebrity(n);
    id == -1 ? cout << "No celebrity" : cout << "Celebrity ID " << id;
    return 0;
}