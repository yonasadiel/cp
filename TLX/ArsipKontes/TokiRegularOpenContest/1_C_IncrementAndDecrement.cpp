#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define mp make_pair
using namespace std;

int main() {
    int n, q;
    ll maxv = 0, minv = 0;
    int t, x;
    ll y;
    scanf("%d%d", &n, &q);
    for (int i=0; i<q; i++) {
        scanf("%d%d%lld", &t, &x, &y);
        if (t == 1) {
            maxv += y;
            if (x == n) minv += y;
        }
        if (t == 2) {
            minv -= y;
            if (x == n) maxv -= y;
        }
    }
    printf("%lld\n", max(maxv, -minv));
}