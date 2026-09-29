#include <stdio.h>
#include <string.h>

#define MAXN 200005

int queueArr[MAXN];
int front, rear, qsize;

void enqueue(int val) {
    rear = (rear + 1) % MAXN;
    queueArr[rear] = val;
    qsize++;
}

int dequeue() {
    int val = queueArr[front];
    front = (front + 1) % MAXN;
    qsize--;
    return val;
}

int isEmpty() {
    return qsize == 0;
}

int bits[MAXN];
char s[MAXN];

int main() {
    int n, m, i, j, x;
    int prev, cur, runLen, best;

    scanf("%s", s + 1);
    n = strlen(s + 1);
    scanf("%d", &m);

    for (i = 1; i <= n; i++) {
        bits[i] = s[i] - '0';
    }

    for (i = 0; i < m; i++) {
        scanf("%d", &x);
        bits[x] ^= 1;

        front = 0;
        rear = -1;
        qsize = 0;
        for (j = 1; j <= n; j++) {
            enqueue(bits[j]);
        }

        best = 0;
        runLen = 0;
        prev = -1;
        while (!isEmpty()) {
            cur = dequeue();
            if (cur == prev) {
                runLen++;
            } else {
                runLen = 1;
                prev = cur;
            }
            if (runLen > best) {
                best = runLen;
            }
        }

        printf(i == 0 ? "%d" : " %d", best);
    }
    printf("\n");

    return 0;
}
