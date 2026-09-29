#include <stdio.h>

#define SIZE 5

int arr[SIZE];
int top1 = -1;
int top2 = SIZE;

void push1(int x) {
    arr[++top1] = x;
}

void push2(int x) {
    arr[--top2] = x;
}

int pop1() {
    return arr[top1--];
}

int pop2() {
    return arr[top2++];
}

int main() {
    int i, value;

    for (i = 0; i < SIZE; i++) {
        scanf("%d", &value);
        if (i % 2 == 0) {
            push1(value);
        } else {
            push2(value);
        }
    }

    printf("Popped element from stack1 is:%d\n", pop1());
    printf("Popped element from stack2 is:%d\n", pop2());

    return 0;
}
