#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> adj[30];
int dp[2][21][21][1500000];

int play(int turn, int pos1, int pos2, int bitmask) {
    int &ret = dp[turn][pos1][pos2][bitmask];
    if (ret == -1) {
        ret = 0;
        if (turn == 0) {
            for (int next: adj[pos1]) {
                if (bitmask & (1 << next)) {
                    // sudah dikunjungi
                } else {
                    ret = max(ret, (next >= n-7) + play(1, next, pos2, bitmask | (1 << next)));
                }
            }
        } else {
            for (int next: adj[pos2]) {
                ret = max(ret, play(0, pos1, next, bitmask | (1 << next)));
            }
        }
    }
    return ret;
}

int main() {
    memset(dp, -1, sizeof dp);
    scanf("%d\n", &n);
    for (int i=0; i<n; i++) {
        int x;
        while (1) {
            scanf("%d", &x);
            adj[i].push_back(x);

            char cc;
            scanf("%c", &cc);
            if (cc == '\n' || cc == '\r') break;
        }
    }

    printf("%d\n", play(0, 0, 0, 0));
}