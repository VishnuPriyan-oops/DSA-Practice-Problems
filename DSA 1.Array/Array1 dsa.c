#include <stdio.h>

int main()
{
    int n, i, j, k;
    int a[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 5, 1};
    char *s[] = {"R", "BR", "G", "BG", "B", "ZB", "P", "ZP", "Z", "W", "B"};

    while (scanf("%d", &n) == 1)
    {
        char buf[] = "                                                                                ";
        i = 0;

        while(n>=10)
        {
            break;
        }

        for (j = 0; j < 11; j++)
        {
            while (n >= a[j])
            {
                k = 0;

                while (s[j][k] != '\0')
                    buf[i++] = s[j][k++];

                n = n - a[j];
            }
        }

        if (i == 0)
            buf[i++] = 'R';

        buf[i] = '\0';
        printf("%s\n", buf);
    }

    return 0;
}
