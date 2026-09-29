#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef char* string;

#define MAX 200

char* stack[MAX];
int top = -1;

void push(char* s) {
    char* copy = (char*)malloc(strlen(s) + 1);
    strcpy(copy, s);
    stack[++top] = copy;
}

char* pop() {
    return stack[top--];
}

int isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

string postToPre(string post_exp) {
    int i, len;
    char ch;
    char *op1, *op2;
    char result[MAX];
    char operand[2];

    len = strlen(post_exp);

    for (i = 0; i < len; i++) {
        ch = post_exp[i];
        if (isOperator(ch)) {
            op2 = pop();
            op1 = pop();
            result[0] = ch;
            result[1] = '\0';
            strcat(result, op1);
            strcat(result, op2);
            push(result);
        } else {
            operand[0] = ch;
            operand[1] = '\0';
            push(operand);
        }
    }

    return pop();
}

int main() {
    char exp[MAX];
    scanf("%s", exp);
    printf("%s\n", postToPre(exp));
    return 0;
}
