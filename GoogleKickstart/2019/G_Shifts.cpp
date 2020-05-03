#include <bits/stdc++.h>
using namespace std;

#define pll pair<long long, long long>

int n;
long long h;
long long a[30], b[30];
int ga[30], gb[30];
long long expr_sum1, expr_sum2;
long long ans;

void brute2(int lo, int hi) {
    if (lo == hi) {
        if (expr_sum1 >= h && expr_sum2 >= h) {
            ans++;
        }
    } else {
        if (ga[lo] == 0) {
            expr_sum1 += a[lo];
            brute2(lo + 1, hi);
            expr_sum1 -= a[lo];

            expr_sum2 += b[lo];
            brute2(lo + 1, hi);
            expr_sum2 -= b[lo];
        } else {
            brute2(lo + 1, hi);
        }
    }
}

void brute(int lo, int hi) {
    if (lo == hi) {
        brute2(0, n);
    } else {
        expr_sum1 += a[lo]; ga[lo] = 1;
        expr_sum2 += b[lo]; gb[lo] = 1;
        brute(lo + 1, hi); // a and b
        expr_sum1 -= a[lo]; ga[lo] = 0;
        expr_sum2 -= b[lo]; gb[lo] = 0;
        brute(lo + 1, hi); // no one
    }
}

void solve(int tc) {
    scanf("%d%lld", &n, &h);
    for (int i = 0; i < n; i++) scanf("%lld", &a[i]);
    for (int i = 0; i < n; i++) scanf("%lld", &b[i]);

    ans = 0LL;
    expr_sum1 = 0LL; expr_sum2 = 0LL; brute(0, n / 2);

    printf("Case #%d: %lld\n", tc, ans);
}

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) solve(i);
}