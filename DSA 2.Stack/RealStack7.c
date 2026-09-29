#include <stdio.h>
#define MAX 3000

int main()
{
    int n,i,j,top=-1;
    long long a[MAX],ans[MAX];
    int ng[MAX],ns[MAX],s[MAX];

    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%lld",&a[i]);

    for(i=n-1;i>=0;i--)
    {
        while(top>=0 && a[s[top]]<=a[i])
            top--;

        ng[i]=(top<0)?-1:s[top];
        s[++top]=i;
    }

    top=-1;

    for(i=n-1;i>=0;i--)
    {
        while(top>=0 && a[s[top]]>=a[i])
            top--;

        ns[i]=(top<0)?-1:s[top];
        s[++top]=i;
    }

    for(j=0;j<n;j++)
        ans[j]=(ng[j]==-1 || ns[ng[j]]==-1)?-1:a[ns[ng[j]]];

    for(j=0;j<n;j++)
        printf("%lld ",ans[j]);

    return 0;
}
