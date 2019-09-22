#include <bits/stdc++.h>
#define ll long long
#define plll tuple<ll, ll, ll>
using namespace std;

ll llpow(ll a, ll b, ll mod) {
    if (b == 0) return 1LL;
    if (b == 1) return a;
    ll c = llpow(a, b / 2, mod) % mod;
    ll d = (c * c) % mod;
    if (b % 2 == 0) return d;
    return (d * a) % mod;
}

ll extended_euclid(ll a, ll b, ll& x, ll& y) {
    if (a == 0) {
        x = 0;
        y = 1;
        return b;
    }
    ll _x, _y;
    ll d = extended_euclid(b % a, a, _x, _y);
    x = _y - (b / a) * _x;
    y = _x;
    return d;
}

ll modinv(ll a, ll m) {
    ll x, y;
    ll g = extended_euclid(a, m, x, y);
    if (g != 1) assert(false); // no modular inverse
    return (x % m + m) % m;
}

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        ll c, e, n;
        scanf("%lld%lld%lld", &c, &e, &n);
        ll p = 0, q;
        for (ll i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                p = i;
                q = n / i;
                break;
            }
        }
        assert(p != 0);
        assert(q != 0);
        ll phi = (p - 1) * (q - 1);
        // printf("%lld %lld = %lld\n", p, q, p * q);
        ll d = modinv(e, phi);
        ll x = llpow(c, d, n);
        printf("%lld\n", x);
    }

}
