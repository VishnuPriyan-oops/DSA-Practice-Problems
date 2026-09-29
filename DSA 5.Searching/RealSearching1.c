#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define LEN 100

int main() {
    char var[3][LEN];
    char key[3];
    double val[3];
    int missing = -1;

    for (int i = 0; i < 3; i++) {
        fgets(var[i], LEN, stdin);
        var[i][strcspn(var[i], "\n")] = '\0';

        char letter;
        char valueStr[LEN];
        sscanf(var[i], "%c %s", &letter, valueStr);

        key[i] = letter;
        if (valueStr[0] == '?') {
            missing = i;
        } else {
            val[i] = atof(valueStr);
        }
    }

    double M = 0, D = 0, X = 0;
    for (int i = 0; i < 3; i++) {
        if (i == missing) continue;
        if (key[i] == 'M') M = val[i];
        else if (key[i] == 'D') D = val[i];
        else if (key[i] == 'X') X = val[i];
    }

    char missingKey = key[missing];
    double result;

    if (missingKey == 'X') {
        result = -M / D;
    } else if (missingKey == 'D') {
        result = -M / X;
    } else {
        result = -D * X;
    }

    printf("%c %.2f\n", tolower(missingKey), result);

    return 0;
}
