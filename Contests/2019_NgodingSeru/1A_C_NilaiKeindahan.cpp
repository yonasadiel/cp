#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define MOD 1000000007
using namespace std;

int n;
int a[1005];
ll *b, *c;

int main() {
    scanf("%d", &n);
    for (int i=0; i<n; i++) {
        scanf("%d", &a[i]);
    }

    c = (ll*) malloc(3000 * sizeof (ll));
    memset(c, 0, sizeof c);
    for (int i=0; i<n; i++) {
        b = (ll*) malloc(3000 * sizeof (ll));
        for (int j=1; j<=2000; j++) { b[j] = c[j]; }

        for (int j=1; j<=2000; j++) {
            int ii = __gcd(a[i], j);
            b[ii] += (a[i] * c[j]) % MOD;
            b[ii] %= MOD;
        }
        b[a[i]] += a[i];
        // for (int j=1; j<=10; j++) { printf("%lld ", b[j]); } printf("\n");
        free(c);
        c = b;
    }
    ll ans = 0;
    for (int i=1; i<=2000; i++) {
        ans += i * c[i];
        ans %= MOD;
    }
    printf("%lld\n", ans);
}