#include <stdio.h>

#define MAX 100000

int main()
{
    int n,i,j,top=-1;
    long long arr[100000],st[100000];
    int stack[100000];
    long long max=0;

    scanf("%d",&n);

    for(i=0;i<n;i++)
        scanf("%lld",&arr[i]);

    for(i=n-1;i>=0;i--)
    {
        while(top>=0)
        {
            j=stack[top];

            if(arr[i]<arr[j])
                break;

            top--;
        }

        if(top==-1)
            st[i]=arr[i];
        else
            st[i]=arr[i]^st[j];

        stack[++top]=i;
    }

    for(i=0;i<n;i++)
    {
        if(st[i]>max)
            max=st[i];
    }

    printf("%lld",max);

    return 0;
}
