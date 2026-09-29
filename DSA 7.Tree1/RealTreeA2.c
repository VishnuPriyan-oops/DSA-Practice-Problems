#include <stdio.h>
#include <stdlib.h>

int pre[100005], in[100005], post[100005];
int pos[100005];
int preIdx;
int postIdx;

void build(int inStart, int inEnd) {
    if (inStart > inEnd) return;
    int rootVal = pre[preIdx++];
    int inRoot = pos[rootVal];
    build(inStart, inRoot - 1);
    build(inRoot + 1, inEnd);
    post[postIdx++] = rootVal;
}

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 1;i<=n;i++) scanf("%d", &pre[i - 1]);
    for (int i = 1;i<=n;i++) {
        scanf("%d", &in[i - 1]);
        pos[in[i - 1]] = i - 1;
    }

    printf("\n");

    preIdx = 0; postIdx = 0;
    build(0, n - 1);

    for (int i = 0; i < n; i++)
        printf("%d%c", post[i], i == n - 1 ? '\n' : ' ');

    return 0;
}
