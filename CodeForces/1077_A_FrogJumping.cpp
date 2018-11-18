#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    long long k, a, b;
    scanf("%d", &n);
    for (int i=0; i<n; i++) {
        scanf("%lld%lld%lld", &a, &b, &k);
        long long ans = a * (k/2 + (k & 1)) - b * (k/2);
        printf("%lld\n", ans);
    }
}