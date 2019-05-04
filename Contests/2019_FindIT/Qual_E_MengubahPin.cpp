#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;

ll ten[10] = {
    1LL, 10LL, 100LL, 1000LL,
    10000LL, 100000LL, 1000000LL,
    10000000LL, 100000000LL, 1000000000LL};

ll fastpow(ll base, ll to, ll mod) {
    ll ans = 1;
    for (ll i=0; i<30; i++) {
        if (to & (1LL << i)) {
            ans *= base;
            ans %= mod;
        }
        base *= base;
        base %= mod;
    }
    return ans;
}

int main() {
    int x, y, z;
    char cc;
    int perm[10];

    scanf("%d%d%d\n", &x, &y, &z);
    assert(x <= 8);
    assert(y <= 20);
    assert(z <= 10000);
    memset(perm, -1, sizeof perm);
    for (int i=0; i<x; i++) {
        scanf("%c", &cc);
        perm[cc-'1'] = i;
    }
    for (int i=0; i<x; i++) assert(perm[i] != -1);
    for (int i=0; i<z; i++) {
        scanf("%c", &cc);
        char a[10];
        for (int j=0; j<x; j++) {
            scanf("%c", &cc);
            a[perm[j]] = cc;
        }
        ll res = 0;
        for (int j=0; j<x; j++) {
            res *= 10;
            res += (ll) a[j] - '0';
        }
        res = fastpow(res, y, ten[x]);
        char form[] = "%04lld%c";
        form[2] = (char) x + '0';
        printf(form, res, (i == z-1 ? '\n' : ' '));
    }
    return 0;
}
