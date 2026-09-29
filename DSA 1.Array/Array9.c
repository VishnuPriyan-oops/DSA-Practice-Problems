#include <stdio.h>

int main()
{
    int r,c,i,j,m,n;
    scanf("%d %d",&r,&c);

    int arr[r][c];
    int arrTemp[r][c];

    for(m=0;m<r;m++)
        for(n=0;n<c;n++)
            scanf("%d",&arr[m][n]);

    for(m=0;m<r;m++)
        for(n=0;n<c;n++)
            arrTemp[m][n]=arr[m][n];

    for(i=0;i<r;i++)
        for(j=0;j<c;j++)
            if(arr[i][j]==1)
            {
                for(m=0;m<r;m++)
                    arrTemp[m][j]=1;

                for(n=0;n<c;n++)
                    arrTemp[i][n]=1;
            }

    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
            printf("%d ",arrTemp[i][j]);
        printf("\n");
    }

    return 0;
}
