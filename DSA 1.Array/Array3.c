#include <stdio.h>

int main()
{
    int t, n, i, j, k, a[10], x;

    scanf("%d", &t);

    while(t--)
    {
        scanf("%d", &n);

        for(i = 0; i < n; i++)
            scanf("%d", &a[i]);

        x = 0;

        for(i = 1; i < n; i++)
        {
            if(a[i] > a[i-1])
            {
                if(i == 1 || a[i-1] <= a[i-2])
                    j = i - 1;

                if(i == n-1 || a[i+1] <= a[i])
                {
                    printf("(%d %d)", j, i);
                    x = 1;
                }
            }
        }

        if(x == 0)
            printf("No Profit");

        printf("\n");
    }

    return 0;
}
