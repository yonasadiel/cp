#include <bits/stdc++.h>
using namespace std;

int n;
long long a[200005];

long long guess(long long x) {
    long long ans = 0;
    long long inten = x;
    for (int i=0; i<n; i++) {
        if (a[i] > inten) inten = a[i];
        ans += abs(a[i] - inten);
        inten++;
    }
    return ans;
}

int main() {
    scanf("%d", &n);
    for (int i=0; i<n; i++) {
        scanf("%lld", &a[i]);
    }
    sort(a, a+n);

    long long lo = -3 * n, hi = 3 * n;
    long long ans = guess(lo);
    while (lo + 9 <= hi) {
        long long mi1 = (2 * lo + hi) / 3;
        long long mi2 = (lo + 2 * hi) / 3;
        long long gmi1 = guess(mi1);
        long long gmi2 = guess(mi2);
        ans = min(ans, min(gmi1, gmi2));
        if (gmi1 < gmi2) {
            hi = mi2 - 1;
        } else {
            lo = mi1 + 1;
        }
    }

    for (long long i=lo; i<=hi; i++) {
        ans = min(ans, guess(i));
    }

    printf("%lld\n", ans);
}