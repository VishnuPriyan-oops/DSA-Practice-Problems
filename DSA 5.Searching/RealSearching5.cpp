#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int T;
    cin >> T;

    vector<int> Ns(T);
    vector<vector<int>> allB(T);

    int k;
    for (k = 1; k <= T; ++k) {
        int N;
        cin >> N;
        string s;
        cin >> s;

        vector<int> b(N + 1);
        for (int i = 1; i <= N; i++) b[i] = s[i - 1] - '0';

        Ns[k - 1] = N;
        allB[k - 1] = b;
    }

    vector<int> answers(T);
    for (int t = 0; t < T; t++) {
        int N = Ns[t];
        vector<int> &b = allB[t];
        int len = (N + 1) / 2;

        int windowSum = 0;
        for (int i = 1; i <= len; i++) windowSum += b[i];

        int best = windowSum;
        for (int i = len + 1; i <= N; i++) {
            windowSum += b[i] - b[i - len];
            best = max(best, windowSum);
        }
        answers[t] = best;
    }

    for (int t = 0; t < T; t++) {
        cout << "\n";
        cout << answers[t] << "\n";
    }

    return 0;
}
