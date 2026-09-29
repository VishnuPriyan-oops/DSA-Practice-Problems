#include <stdio.h>

#define MAX 100

int s[MAX];

#define read(x) scanf("%d",&x)

void sol()
{
    int n,i,j,c=0,ans=0,t;

    read(n);

    for(i=0;i<n;i++)
        read(s[i]);

    for(i=0;i<n;i++)
        for(j=i+1;j<n;j++)
            if(s[i]>s[j])
            {
                t=s[i];
                s[i]=s[j];
                s[j]=t;
            }

    for(i=0;i<n;i++)
    {
        if(i==0 || s[i]!=s[i-1])
            c++;

        ans+=c;
    }

    printf("%d\n",ans);
}

int main()
{
    int t;

    scanf("%d",&t);

    while(t--)
    {
        sol();
    }

    return 0;
}
