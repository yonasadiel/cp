#include<bits/stdc++.h>
using namespace std;

long long guess(long long base, long long x) {
    long long res = 1000000000000000000;
    for (long long i = 2; i <= base; i++) {
        if (base % i == 0) {
            int cnt = 0;
            while (base % i == 0) {
                cnt++;
                base /= i;
            }
            long long ans = 0;
            long long run = i;

            while (run <= x) {
                ans += x / run;
                run *= i;
            }
            res = min(res, ans/cnt);
        }
    }
    return res;
}

int main() {
    int t;
    int b;
    long long n;

    scanf("%d", &t);
    while (t--) {
        scanf("%d%lld\n", &b, &n);
        int newb = b;

        long long lo = 1;
        long long hi = 1e18;
        long long ans = hi;
        while (lo <= hi) {
            //printf("%lld %lld %lld\n", lo, hi, ans);
            long long mi = (lo + hi) / 2;
            long long gmi = guess(newb, mi);
            if (gmi >= n) {
                ans = min(ans, mi);
                hi = mi - 1;
            } else {
                lo = mi + 1;
            }
        }
        if (ans >= 1e18) return 1;
        if (guess(newb, ans) == n) printf("%lld\n", ans);
        else printf("-1\n");
    }
}