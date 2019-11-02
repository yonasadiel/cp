#include <bits/stdc++.h>
using namespace std;

int n;
char s[100005];
int pre[100005][5];

int query_pre(int ct, int lo, int hi) {
    int ans = pre[hi][ct];
    if (lo > 0) ans -= pre[lo - 1][ct];
    return ans;
}

int query(int ct, int lo, int hi) {
    lo = (lo + 2 * n) % n;
    hi = (hi + 2 * n) % n;
    if (lo <= hi) return query_pre(ct, lo, hi);
    return query_pre(ct, 0, hi) + query_pre(ct, lo, n - 1);
}

void solve() {
    scanf("%s\n", s);
    n = strlen(s);

    memset(pre, 0, sizeof pre);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 4; j++) {
            pre[i][j] = i == 0 ? 0 : pre[i - 1][j];
        }
        pre[i][s[i] - 'A']++;
    }

    int ca = pre[n - 1][0];
    int cb = pre[n - 1][1];
    int cc = pre[n - 1][2];
    int cd = pre[n - 1][3];

    int ans = n;
    // printf("%s\n", s);
    for (int i = 0; i < n; i++) {
        // abcd
        ans = min(ans,
            ca - query(0, i               , i + ca - 1) +
            cb - query(1, i + ca          , i + ca + cb - 1) +
            cc - query(2, i + ca + cb     , i + ca + cb + cc - 1) +
            cd - query(3, i + ca + cb + cc, i - 1)
        );
        // abdc
        ans = min(ans,
            ca - query(0, i               , i + ca - 1) +
            cb - query(1, i + ca          , i + ca + cb - 1) +
            cd - query(3, i + ca + cb     , i + ca + cb + cd - 1) +
            cc - query(2, i + ca + cb + cd, i - 1)
        );
        // acbd
        ans = min(ans,
            ca - query(0, i               , i + ca - 1) +
            cc - query(2, i + ca          , i + ca + cc - 1) +
            cb - query(1, i + ca + cc     , i + ca + cc + cb - 1) +
            cd - query(3, i + ca + cc + cb, i - 1)
        );
        // acdb
        ans = min(ans,
            ca - query(0, i               , i + ca - 1) +
            cc - query(2, i + ca          , i + ca + cc - 1) +
            cd - query(3, i + ca + cc     , i + ca + cc + cd - 1) +
            cb - query(1, i + ca + cc + cd, i - 1)
        );
        // adbc
        ans = min(ans,
            ca - query(0, i               , i + ca - 1) +
            cd - query(3, i + ca          , i + ca + cd - 1) +
            cb - query(1, i + ca + cd     , i + ca + cd + cb - 1) +
            cc - query(2, i + ca + cd + cb, i - 1)
        );
        // adcb
        ans = min(ans,
            ca - query(0, i               , i + ca - 1) +
            cd - query(3, i + ca          , i + ca + cd - 1) +
            cc - query(2, i + ca + cd     , i + ca + cd + cc - 1) +
            cb - query(1, i + ca + cd + cc, i - 1)
        );
    }
    printf("%d\n", ans);
}

int main() {
    int t;
    scanf("%d\n", &t);
    while (t--) solve();
}