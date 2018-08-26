#include <bits/stdc++.h>
#define fi first
#define se second.first
#define th second.second
#define piii pair<double, pair<double, double> >
using namespace std;

piii a[100005];

double jarak0(piii a) {
    return sqrt(
        a.fi * a.fi +
        a.se * a.se +
        a.th * a.th
    );
}

bool cmp(piii a, piii b) {
    return jarak0(a) < jarak0(b);
}

void solve(int tc) {
    int n;
    double r;
    scanf("%d%lf", &n, &r);
    for (int i=0; i<n; i++) {
        scanf("%lf%lf%lf", &a[i].fi, &a[i].se, &a[i].th);
    }
    sort(a, a+n, cmp);

    double t = jarak0(a[0]);
    for (int i=1; i<n; i++) {
        if (jarak0(a[i]) - t > r) {
            t += jarak0(a[i]) - t - r;
        }
        t += r;
    }
    printf("%.12lf\n", t);
}

int main() {
    solve(0);
    return 0;
    int t;
    scanf("%d", &t);
    for (int i=1; i<=t; i++) {
        solve(i);
    }
}