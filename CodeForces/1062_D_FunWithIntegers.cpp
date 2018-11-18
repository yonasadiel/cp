#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ll n;
    scanf("%lld", &n);
    ll ans = 0;
    for (ll i=2; i<=n; i++) {
        for (ll j=i*2; j<=n; j+=i) {
            ans += j/i;
        }
    }
    printf("%lld\n", ans*4);
}