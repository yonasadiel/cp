#include <bits/stdc++.h>
using namespace std;

int n, m, q;
int r[100005], p[100005];
int fact[100005];

void solve(int tc) {
    memset(fact, 0, sizeof fact);
    scanf("%d%d%d", &n, &m, &q);
    for (int i = 0; i < m; i++) {
        scanf("%d", &p[i]);
        for (int j = 1; j <= p[i] / j; j++) {
            if (p[i] % j == 0) {
                fact[j]++;
                if (p[i] / j != j) fact[p[i] / j]++;
            }
        }
    }

    long long ans = 0;
    for (int i = 0; i < q; i++) {
        scanf("%d", &r[i]);
        // printf("%d: %d %d\n",i,  r[i], fact[r[i]]);
        ans += n / r[i] - fact[r[i]];
    }

    printf("Case #%d: %lld\n", tc, ans);
}

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) {
        solve(i);
    }
}