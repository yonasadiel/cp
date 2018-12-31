#include <bits/stdc++.h>
using namespace std;

int n;
long long x, y, tx, ty;

int main() {
    scanf("%d", &n);
    tx = 0, ty = 0;
    for (int i=0; i<n; i++) {
        scanf("%lld%lld", &x, &y);
        tx += x, ty += y;
    }
    for (int i=0; i<n; i++) {
        scanf("%lld%lld", &x, &y);
        tx += x, ty += y;
    }
    printf("%lld %lld\n", tx/n, ty/n);
}