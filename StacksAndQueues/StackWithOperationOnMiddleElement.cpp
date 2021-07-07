#include <bits/stdc++.h>
using namespace std;

struct DllNode {
    int data;
    struct DllNode *next;
    struct DllNode *prev;
};

struct Stack {
    struct DllNode *head;
    struct DllNode *mid;
    int count;
};

struct Stack *createStack() {
    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
    stack->count = 0;
    return stack;
}

void push(struct Stack *stack, int key) {
    struct DllNode *newNode = (struct DllNode *)malloc(sizeof(struct DllNode));

    newNode->data = key;
    newNode->prev = NULL;
    newNode->next = stack->head;

    stack->count++;

    if (stack->count == 1)
        stack->mid = newNode;
    else {
        stack->head->prev = newNode;
        if (stack->count & 1)
            stack->mid = stack->mid->prev;
    }

    stack->head = newNode;
}

int pop(struct Stack *stack) {
    if (stack->count == 0) {
        cout << "Stack Underflow Exception" << endl;
        return -1;
    }

    struct DllNode *res = stack->head;
    int item = res->data;

    stack->head = stack->head->next;

    if (stack->head)
        stack->head->prev = NULL;

    stack->count--;

    if (!(stack->count & 1))
        stack->mid = stack->mid->next;

    free(res);

    return item;
}

int findMiddle(struct Stack *stack) {
    if (stack->count == 0) {
        cout << "Empty Stack" << endl;
        return -1;
    }

    return stack->mid->data;
}

int main() {
    struct Stack *ms = createStack();
    push(ms, 11);
    push(ms, 22);
    push(ms, 33);
    push(ms, 44);
    push(ms, 55);
    push(ms, 66);
    push(ms, 77);

    printf("Item popped is %d\n", pop(ms));
    printf("Item popped is %d\n", pop(ms));
    printf("Middle Element is %d\n", findMiddle(ms));

    return 0;
}