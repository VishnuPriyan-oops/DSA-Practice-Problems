#include <stdio.h>

#define MAX 10
#define LEN 100

int main()
{
    int a, items, i, j, k, x, c = 0;
    char name[MAX][LEN];
    int price[MAX], afford[MAX];

    scanf("%d %d", &a, &items);

    for(i=0;i<items;i++)
    {
        scanf("%s %d", name[i], &price[i]);
        afford[i]=0;
    }

    for(i=0;i<items;i++)
    {
        x=-1;

        for(j=0;j<items;j++)
            if(afford[j]==0 && price[j]<=a)
                if(x==-1 || price[j]<price[x])
                    x=j;

        if(x==-1)
            break;

        a-=price[x];
        afford[x]=1;
        c=1;
    }

    for(i=0;i<items;i++)
        if(afford[i])
            printf("I can afford %s\n", name[i]);
        else
            printf("I can't afford %s\n", name[i]);

    if(c==0)
        printf("I need more Dollar!\n");
    else
        printf("%d\n",a);

    return 0;
}
