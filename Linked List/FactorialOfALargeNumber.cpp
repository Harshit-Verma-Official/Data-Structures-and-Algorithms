#include <bits/stdc++.h>
using namespace std;

class Num {
public:
    int data;
    Num *prev;
    Num(int data) {
        this->data = data;
        this->prev = nullptr;
    }
};

Num *multiply(Num *tail, int n) {
    Num *prev = tail;
    int carry = 0;
    while (tail != nullptr) {
        int data = tail->data * n + carry;
        tail->data = data % 10;
        carry = data / 10;
        prev = tail;
        tail = tail->prev;
    }
    while (carry != 0) {
        prev->prev = new Num(carry % 10);
        carry /= 10;
    }
}

void printList(Num *tail) {
    if (tail == nullptr)
        return;
    printList(tail->prev);
    cout << tail->data;
}

void printFactorial(int n) {
    Num *tail = new Num(1);
    for (int i = 1; i <= n; ++i)
        multiply(tail, i);
    printList(tail);
}

int main() {

    printFactorial(2000);

    return 0;
}