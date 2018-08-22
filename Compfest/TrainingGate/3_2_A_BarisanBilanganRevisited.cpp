#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define mp make_pair
#define pii pair<int, int>
using namespace std;

const int dr[] = {0, 1, -1, 0, 1, 1, -1, -1};
const int dc[] = {1, 0, 0, -1, 1, -1, 1, -1};

bool in_bound(pii _p, int _max_fi, int _max_se) {
    return _p.fi >= 0 && _p.fi < _max_fi && _p.se >= 0 && _p.se < _max_se;
}

ll lcm(ll a, ll b) { return a/__gcd(a,b)*b; }

int n, a, b;

bool valid(ll x) {
    return n <= (x/a) + (x/b) - (x/lcm(a, b));
}

int main() {
    scanf("%d%d%d", &n, &a, &b);

    ll lo = 1;
    ll hi = 1000000000000000;
    while (lo < hi) {
        ll mi = (lo+hi)/2;
        if (valid(mi) && !valid(mi-1)) {
            lo = hi = mi;
        } else if (valid(mi)) {
            hi = mi-1;
        } else {
            lo = mi+1;
        }
    }

    printf("%lld\n", lo);
}