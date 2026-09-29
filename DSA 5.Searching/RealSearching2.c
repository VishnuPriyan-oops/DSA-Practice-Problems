#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAXP 100
#define BUFLEN 128

char *gems[] = {"NONE","Garnet","Amethyst","Aquamarine","Diamond","Emerald","Pearl","Ruby","Peridot","Sapphire","Tourmaline","Topaz","Lapis",0};

int ci(const char *a, const char *b) {
    while (*a && *b) {
        int x = tolower((unsigned char)*a), y = tolower((unsigned char)*b);
        if (x != y) return x - y;
        a++; b++;
    }
    return tolower((unsigned char)*a) - tolower((unsigned char)*b);
}

int rankOf(char *name) {
    char buf[BUFLEN]; strcpy(buf, name);
    int best = 0;
    for (char *t = strtok(buf, " "); t; t = strtok(NULL, " "))
        for (int i = 1; gems[i]; i++)
            if (ci(t, gems[i]) == 0 && i > best) best = i;
    return best;
}

int main() {
    char original[MAXP][BUFLEN], ponies[MAXP][BUFLEN];
    int rank[MAXP], n = 0, i;
    char line[BUFLEN];

    while (fgets(line, BUFLEN, stdin)) {
        line[strcspn(line, "\r\n")] = 0;
        if (!strcmp(line, "END")) break;
        if (!line[0]) continue;

        strcpy(original[n], line);
        for (i = 0; line[i]; i++) ponies[n][i] = tolower((unsigned char)line[i]);
        ponies[n][i] = 0;
        rank[n] = rankOf(ponies[n]);
        n++;
    }

    for (i = 0; i < n - 1; i++)
        for (int a = 0; a < n - 1 - i; a++) {
            int b = a + 1, sw;
            if (rank[a] != rank[b]) sw = rank[a] < rank[b];
            else sw = strcmp(ponies[a],ponies[b])>0;

            if (sw) {
                char t[BUFLEN];
                strcpy(t, original[a]); strcpy(original[a], original[b]); strcpy(original[b], t);
                strcpy(t, ponies[a]); strcpy(ponies[a], ponies[b]); strcpy(ponies[b], t);
                int r = rank[a]; rank[a] = rank[b]; rank[b] = r;
            }
        }

    for (i = 0; i < n; i++) printf("%s\n", original[i]);
    return 0;
}
