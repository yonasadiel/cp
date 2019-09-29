#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

int h, w;
int r[1005], c[1005];
int p[1005][1005];

int main() {
    scanf("%d%d", &h, &w);
    memset(p, -1, sizeof p);
    long long ans = 1;

    for (int i = 0; i < h; i++) {
        scanf("%d", &r[i]);
        for (int j = 0; j < r[i]; j++) {
            if (p[i][j] == 0) ans = 0;
            p[i][j] = 1;
        }
        if (p[i][r[i]] == 1) ans = 0;
        p[i][r[i]] = 0;
    }

    for (int i = 0; i < w; i++) {
        scanf("%d", &c[i]);
        for (int j = 0; j < c[i]; j++) {
            if (p[j][i] == 0) ans = 0;
            p[j][i] = 1;
        }
        if (p[c[i]][i] == 1) ans = 0;
        p[c[i]][i] = 0;
    }

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (p[i][j] == -1) {
                ans *= 2;
                ans %= MOD;
            }
        }
    }

    printf("%lld\n", ans);
}