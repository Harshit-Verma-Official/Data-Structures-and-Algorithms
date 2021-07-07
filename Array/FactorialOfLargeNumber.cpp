#include <bits/stdc++.h>
using namespace std;

#define MAX_SIZE 5000

int multiply(int res[], int res_size, int n) {
    int carry = 0;
    for (int i = 0; i < res_size; ++i) {
        int data = res[i] * n + carry;
        res[i] = data % 10;
        carry = data / 10;
    }
    while (carry) {
        res[res_size++] = carry % 10;
        carry /= 10;
    }
    return res_size;
}

void printFactorial(int n) {
    int res[MAX_SIZE];
    res[0] = 1;
    int res_size = 1;
    for (int i = 2; i <= n; ++i)
        res_size = multiply(res, res_size, i);
    for (int i = res_size - 1; i >= 0; --i)
        cout << res[i];
}

int main() {

    printFactorial(10);

    return 0;
}