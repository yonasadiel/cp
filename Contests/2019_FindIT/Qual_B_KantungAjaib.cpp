#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll gcd(ll a, ll b, ll &x, ll &y) {
    if (a == 0) {
        x = 0; y = 1;
        return b;
    }
    ll x1, y1;
    ll d = gcd(b%a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        ll x, p, s, u;
        ll xx, pp, ss, uu;
        scanf("%lld%lld%lld%lld", &x, &p, &s, &u);
        xx = x, pp = p, ss = s, uu = u;
        ll pem = __gcd(s, u);

        s /= pem;
        u /= pem;
        x /= __gcd(x, pem);

        ll a, b;
        ll g = gcd(s, x, a, b);
        if (g != 1) {
            printf("TIDAK\n");
        } else {
            a = (a % x + x) % x;
            a = (a * u) % x;
            if (a > p) {
                printf("TIDAK\n");
            } else {
                a = a + ((p-a) / x) * x;
                if (a * ss > uu) {
                    printf("YA %lld\n", a);
                } else {
                    printf("TIDAK\n");
                }
            }
        }
    }
}