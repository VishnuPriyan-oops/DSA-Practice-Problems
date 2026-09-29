#include <stdio.h>

int main()
{
    int p, q, i, j, a, b, c;
    int top = 0, bottom, left = 0, right;

    scanf("%d %d", &p, &q);

    bottom = p - 1;
    right = q - 1;
    while(top<=bottom && right>=left)
    {
        top++;
        bottom--;
        left++;
        right--;
    }
    for(i = 0; i < p; i++)
    {
        for(j = 0; j < q; j++)
        {
            a = i < p-1-i ? i : p-1-i;
            b = j < q-1-j ? j : q-1-j;
            c = a < b ? a : b;

            printf(c % 2 == 0 ? "Y " : "0 ");
        }
        printf("\n");
    }
    return 0;
}
