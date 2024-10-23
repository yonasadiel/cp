#include<iostream>
using namespace std;

void solve(int tc) {
    long long n, k, x, y = 100000000000LL;
    scanf("%lld%lld", &n, &k);
    for (int i=0; i<n; i++) {
        scanf("%lld", &x);
        y = min(y, x);
    }
    printf("Case #%d: ", tc);
    bool bisa = false;
    if (n == 1) bisa = y <= k;
    else        bisa = y * ((n-1)*2-1) <= k;
    if (bisa) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
}

int main() {
    int t;
    scanf("%d", &t);
    for (int i=1; i<=t; i++) solve(i);
}
