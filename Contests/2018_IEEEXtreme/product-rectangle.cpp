#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n,m;
ll a[2005], b[2005];
ll prea[2005], preb[2005];
vector<ll> posa, posb;

int main() {
    scanf("%d%d", &n, &m);
    for (int i=0; i<n; i++) {
        scanf("%lld", &a[i]);
        prea[i] = a[i] + (i > 0? prea[i-1] : 0);
    }
    for (int i=0; i<m; i++) {
        scanf("%lld", &b[i]);
        preb[i] = b[i] + (i > 0? preb[i-1] : 0);
    }

    for (int i1=0; i1<n; i1++) {
        for (int i2=i1; i2<n; i2++) {
            ll asum = prea[i2]; if (i1 > 0) asum -= prea[i1 - 1];
            posa.push_back(asum);
        }
    }

    for (int i1=0; i1<m; i1++) {
        for (int i2=i1; i2<m; i2++) {
            ll bsum = preb[i2]; if (i1 > 0) bsum -= preb[i1 - 1];
            posb.push_back(bsum);
        }
    }

    sort(posa.begin(), posa.end());
    sort(posb.begin(), posb.end());

    ll ans = posa[0] * posb[0];
    ans = max(ans, posa[posa.size() - 1] * posb[posb.size() - 1]);
    ans = max(ans, posa[posa.size() - 1] * posb[0]);
    ans = max(ans, posa[0] * posb[posb.size() - 1]);
    printf("%lld\n", ans);
}