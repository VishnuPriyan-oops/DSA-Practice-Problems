#include <stdio.h>

int main()
{
    char nums[13][256] = {
        "ZERO","ONE","TWO","THREE","FOUR","FIVE","SIX",
        "SEVEN","EIGHT","NINE","TEN","ELEVEN","TWELVE"
    };

    int a[100], x[26] = {0};
    int i = 0, n, j, k;

    while (scanf("%d", &a[i]) == 1 && a[i] != 999)
        i++;

    for (j = 0; j < i; j++)
    {
        if (a[j] >= 0 && a[j] <= 12)
        {
            for (k = 0; nums[a[j]][k] != '\0'; k++)
                x[nums[a[j]][k] - 'A']++;
        }
    }

    for (j = 0; j < i; j++)
        printf("%d ", a[j]);

    printf("999. ");

    for(n=0;n<26;n++)
        while (x[n]--)
            printf("%c ", n + 'A');

    return 0;
}
