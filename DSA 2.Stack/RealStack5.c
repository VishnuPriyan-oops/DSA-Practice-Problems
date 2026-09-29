#include <stdio.h>
#include <string.h>

#define MAX 1000

char stack[MAX];
int top = -1;

void push(char ch)
{
    stack[++top] = ch;
}

char pop()
{
    return stack[top--];
}

int empty()
{
    return top == -1;
}

int match(char a, char b)
{
    return (a == '(' && b == ')') ||
           (a == '[' && b == ']') ||
           (a == '{' && b == '}');
}

int main()
{
    char exp[MAX];
    int i, balanced = 1;
    char ch, x;

    scanf("%s", exp);

    for (i = 0; exp[i] != '\0'; i++)
    {
        ch = exp[i];

        if (ch == '(' || ch == '[' || ch == '{')
            push(ch);

        else
        {
            if (empty())
            {
                balanced = 0;
                break;
            }

            x = pop();

            if (!match(x, ch))
            {
                balanced = 0;
                break;
            }
        }
    }

    if (!empty())
        balanced = 0;

    if (balanced)
        printf("Balanced");
    else
        printf("Not Balanced");

    return 0;
}
