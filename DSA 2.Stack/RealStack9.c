#include <stdio.h>

#define MAX 100000

int q[MAX], front = 0, rear = 0, size = 0;

void qpush(int val)
{
    q[rear++] = val;
    size++;
}

int qpop()
{
    int val = q[front++];
    size--;
    return val;
}

void push(int val)
{
    int n, i;

    n = size;
    qpush(val);

    for(i=0;i<n;i++)
        qpush(qpop());
}

int pop()
{
    if(size == 0)
        return -1;

    return qpop();
}

int main()
{
    int n,m,i,val,top;

    scanf("%d %d",&n,&m);

    for(i=0;i<n;i++)
    {
        scanf("%d",&val);
        push(val);
    }

    top = q[front];

    printf("top of element %d\n",top);

    for(i=0;i<m;i++)
        pop();

    if(size > 0)
        printf("top of element %d",q[front]);
    else
        printf("top of element -1");

    return 0;
}
