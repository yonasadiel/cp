#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

int n, m;
pair<long long, int> t[100005];

long long fastpow(long long a, long long b) {
    long long ans = 1, base = a;
    for (int i=0; i<62; i++) {
        if (b & (1LL << i)) {
            ans *= base;
            ans %= MOD;
        }
        base *= base;
        base %= MOD;
    }
    // printf("fastpow(%lld, %lld) = %lld\n", a, b, ans);
    return ans;
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i=0; i<m; i++) {
        scanf("%lld", &t[i].first);
        t[i].second = i;
    }
    sort(t, t+m);
    long long ans = 1;
    long long last = n;
    long long cnt = 0;
    for (int i=m-1; i>=0; i--) {
        if (t[i].first < last)
            ans *= fastpow(cnt, last - t[i].first);
        ans %= MOD;
        cnt++;
        last = t[i].first - 1;
    }
    if (last > 0)
    ans *= fastpow(cnt, last);
    ans %= MOD;
    printf("%lld\n", ans);
}
