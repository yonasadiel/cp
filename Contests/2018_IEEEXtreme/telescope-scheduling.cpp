#include <bits/stdc++.h>
#define piii pair<pair<int, int>, int >
#define fi first.first
#define se first.second
#define th second
using namespace std;

int n;
piii a[10005];
int c[10005];
int ne[10005];
int dp[10005];

int play(int pos) {
    int &ret = dp[pos];
    if (ret == -1) {
        if (pos == n) {
            ret = 0;
        } else {
            ret = max(play(pos+1), a[pos].th + play(ne[pos]));
        }
    }
    return ret;
}

int main() {
    scanf("%d", &n);
    for (int i=0; i<n; i++) {
        scanf("%d%d%d", &a[i].fi, &a[i].se, &a[i].th);
    }

    sort(a, a + n);
    for (int i=0; i<n; i++) {
        c[i] = a[i].fi;
    }
    for (int i=0; i<n; i++) {
        ne[i] = upper_bound(c, c+n, a[i].se) - c;
    }

    memset(dp, -1, sizeof dp);
    printf("%d\n", play(0));
}