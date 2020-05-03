#include <bits/stdc++.h>
using namespace std;

int n;
long long m;
long long a[1005];
long long diff[70];

void solve(int tc) {
    long long s = 0LL;
    scanf("%d%lld", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        s += a[i];
    }
    memset(diff, 0, sizeof(diff));
    for (int bit = 0; bit <= 50; bit++) {
        diff[bit] = 0LL;
        for (int i = 0; i < n; i++) {
            if (a[i] & (1LL << bit)) {
                diff[bit] -= (1LL << bit);
            } else {
                diff[bit] += (1LL << bit);
            }
        }
    }

    long long ans = 0LL;
    for (int bit = 50; bit >= 0; bit--) {
        if (diff[bit] <= 0LL) {
            ans |= (1LL << bit);
            s += diff[bit];
        }
    }
    for (int bit = 50; bit >= 0; bit--) {
        if (diff[bit] > 0LL && s + diff[bit] <= m) {
            ans |= (1LL << bit);
            s += diff[bit];
        }
    }
    if (s > m) ans = -1LL;
    printf("Case #%d: %lld\n", tc, ans);
}

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) solve(i);
}