#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n, k;

int solve() {
    ll ans = -1;
    for (int i = 1; i < k; i++) {
        if (n % i == 0) {
            ll tans = (ll) (n / i) * k + i;
            if (ans == -1) ans = tans;
            else ans = min(tans, ans);
        }
    }
    if (ans == -1) {
        assert(false);
    } else {
        printf("%lld\n", ans);
    }
}

int main() {
    while (scanf("%d%d", &n, &k) == 2) {
        solve();
    }
}