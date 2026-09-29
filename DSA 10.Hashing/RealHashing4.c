#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int B[100005], G[100005];
int boy_beat[100005], girl_beat[100005];
int boy_target[100005], girl_target[100005];

void reset_arrays() {
    memset(boy_beat, 0, sizeof(boy_beat));
    memset(girl_beat, 0, sizeof(girl_beat));
    memset(boy_target, 0, sizeof(boy_target));
    memset(girl_target, 0, sizeof(girl_target));
}

void process_students(int N) {
    for (int i = 1; i <= N; i++) {
        int bt = G[B[i]];
        if (bt != i) {
            boy_target[i] = bt;
            boy_beat[bt]++;
        }
        int gt = B[G[i]];
        if (gt != i) {
            girl_target[i] = gt;
            girl_beat[gt]++;
        }
    }
}

int get_max_beat() {
    int max_beat = 0;
    for (int i = 0; i <= 100000; i++) {
        if (boy_beat[i] > max_beat) max_beat = boy_beat[i];
        if (girl_beat[i] > max_beat) max_beat = girl_beat[i];
    }
    return max_beat;
}

int get_mutual_pairs() {
    int count = 0;
    for (int i = 1; i <= 100000; i++) {
        if (boy_target[i] > i && boy_target[boy_target[i]] == i) count++;
        if (girl_target[i] > i && girl_target[girl_target[i]] == i) count++;
    }
    return count;
}

void solve() {
    int N;
    if (scanf("%d", &N) != 1) return;
    for (int i = 1; i <= N; i++) scanf("%d", &B[i]);
    for (int i = 1; i <= N; i++) scanf("%d", &G[i]);

    reset_arrays();
    process_students(N);

    printf("%d %d\n", get_max_beat(), get_mutual_pairs());
}

int main() {
    int T, tc = 0;
    if (scanf("%d", &T) != 1) return 0;
    while (true) {
        if (tc >= T) break;
        tc++;
        solve();
    }
    return 0;
}
