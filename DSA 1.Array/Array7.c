#include <stdio.h>

int main()
{
    int t, n, m, i, j, x1, y1, x2, y2, s;

    scanf("%d", &t);

    while(t--)
    {
        scanf("%d %d", &n, &m);

        int C[m][n];

        for(i=0;i<n;i++)
            for(j=0;j<m;j++)
                scanf("%d", &C[i][j]);

        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

        s=0;

        for(i=x1-1;i<x2;i++)
            for(j=y1-1;j<y2;j++)
                s+=C[i][j];

        printf("%d\n",s);
    }

    return 0;
}
