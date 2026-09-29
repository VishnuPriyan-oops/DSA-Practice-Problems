#include <stdio.h>
#include <string.h>

typedef struct {
    char name[12];
    long long m1, m2, m3;
    int used;
} Fest;

Fest ht[20007];

void add(char *s, long long x) {
    unsigned int h = 0;
    for (int i = 0; s[i]; i++) h = (h * 31 + s[i]) % 20007;
    while (ht[h].used && strcmp(ht[h].name, s)) h = (h + 1) % 20007;
    if (!ht[h].used) {
        ht[h].used = 1;
        strcpy(ht[h].name, s);
    }
    if (x > ht[h].m1) { ht[h].m3 = ht[h].m2; ht[h].m2 = ht[h].m1; ht[h].m1 = x; }
    else if (x > ht[h].m2) { ht[h].m3 = ht[h].m2; ht[h].m2 = x; }
    else if (x > ht[h].m3) { ht[h].m3 = x; }
}

int main() {
    int t, tc = 0;
    if (scanf("%d", &t) != 1) return 0;
    int total_t = t;
    char ans_s[105][12];
    long long ans_v[105];

    while(t--) {
        int n;
        scanf("%d", &n);
        memset(ht, 0, sizeof(ht));
        for (int i = 0; i < n; i++) {
            char s[12];
            long long x;
            scanf("%s %lld", s, &x);
            add(s, x);
        }
        char best[12] = "";
        long long max_sum = -1;
        for (int i = 0; i < 20007; i++) {
            if (!ht[i].used) continue;
            long long sum = ht[i].m1 + ht[i].m2 + ht[i].m3;
            if (sum > max_sum || (sum == max_sum && strcmp(ht[i].name, best) < 0)) {
                max_sum = sum;
                strcpy(best, ht[i].name);
            }
        }
        strcpy(ans_s[tc], best);
        ans_v[tc++] = max_sum;
    }

    printf("\n");
    for (int i = 0; i < total_t; i++) {
        printf("%s %lld\n", ans_s[i], ans_v[i]);
    }

    return 0;
}
