#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *dupStr(const char *s) {
    char *p = malloc(strlen(s) + 1);
    strcpy(p, s);
    return p;
}

#define CMDS 5
#define TOKENS 4
#define MAXWORDS 1000
#define MAXLEN 200

char *cmds[CMDS] = {"NOUNS","ADVERBS","VERBS","ADJECTIVES","END"};
char *tokens[TOKENS] = {"[N]","[AV]","[V]","[AJ]"};
char *lists[CMDS][MAXWORDS];
int cl[CMDS];

int main() {
    char sentence[MAXLEN];
    fgets(sentence, sizeof(sentence), stdin);
    sentence[strcspn(sentence, "\r\n")] = 0;

    for (int i = 0; i < CMDS; i++) cl[i] = 0;

    char line[MAXLEN];
    int current = -1;
    while (fgets(line, sizeof(line), stdin)) {
        line[strcspn(line, "\r\n")] = 0;
        if (line[0] == '\0') continue;

        int matchedCmd = -1;
        for (int i = 0; i < CMDS; i++) {
            if (strcmp(line, cmds[i]) == 0) { matchedCmd = i; break; }
        }
        if (matchedCmd == 4) break;
        if (matchedCmd != -1) { current = matchedCmd; continue; }

        lists[current][cl[current]] = dupStr(line);
        cl[current]++;
    }

    int idx[CMDS];
    for (int i = 0; i < CMDS; i++) idx[i] = 0;

    printf("\n");

    for (int rep = 0; rep < 2; rep++) {
        char output[MAXLEN * 4];
        int outPos = 0;
        int len = strlen(sentence);

        for (int i = 0; i < len; ) {
            int matchedTok = -1;
            for (int t = 0; t < TOKENS; t++) {
                int tl = strlen(tokens[t]);
                if (strncmp(&sentence[i], tokens[t], tl) == 0) { matchedTok = t; break; }
            }

            if (matchedTok != -1) {
                char *word = lists[matchedTok][idx[matchedTok]];
                idx[matchedTok]++;
                int wl = strlen(word);
                memcpy(&output[outPos], word, wl);
                outPos += wl;
                i += strlen(tokens[matchedTok]);
            } else {
                output[outPos++] = sentence[i];
                i++;
            }
        }
        output[outPos] = '\0';
        printf("%s\n", output);
    }

    return 0;
}
