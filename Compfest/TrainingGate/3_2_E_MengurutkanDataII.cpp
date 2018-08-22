#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define mp make_pair
#define pii pair<int, int>
#define MOD 1000000007
using namespace std;

const int dr[] = {0, 1, -1, 0, 1, 1, -1, -1};
const int dc[] = {1, 0, 0, -1, 1, -1, 1, -1};

bool in_bound(pii _p, int _max_fi, int _max_se) {
    return _p.fi >= 0 && _p.fi < _max_fi && _p.se >= 0 && _p.se < _max_se;
}

ll lcm(ll _a, ll _b) { return _a / __gcd(_a,_b) * _b; }

ll pangkat(ll _base, ll _to) {
    ll _ans = 1LL;
    for (int _i=0; _i<64; _i++) {
        if (_to & (1LL << _i)) {
            _ans *= _base;
            _ans %= MOD;
        }
        _base *= _base;
        _base %= MOD;
    }
    return _ans;
}

int n;
int a[100005];

int main() {
    scanf("%d", &n);
    for (int i=0; i<n; i++) {
        scanf("%d", &a[i]);
    }
    sort(a, a+n);

    for (int i=0; i<n; i++) {
        printf("%d", a[i]);
        if (i == n-1) printf("\n");
        else printf(" ");
    }
}
