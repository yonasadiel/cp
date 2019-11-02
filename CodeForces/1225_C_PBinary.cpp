#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, p;
    long long b = 1LL;

    scanf("%lld %lld", &n, &p);
    long long x = n;
    int ans = -1;
    for (int i = 0; i <= 1000 && x >= 0; i++) {
        if (__builtin_popcount(x) <= i && i <= x) {
            ans = i;
            break;
        }
        x = x - p;
    }
    printf("%d\n", ans);
}