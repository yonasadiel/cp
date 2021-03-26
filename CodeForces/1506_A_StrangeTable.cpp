#include <cstdio>
using namespace std;

void solve() {
    long long n, m, x;
    scanf("%lld%lld%lld\n", &n, &m, &x);
    x--;
    long long ans = (x % n) * m + (x / n);
    ans++;
    printf("%lld\n", ans);
}

int main() {
    int tc;
    scanf("%d", &tc);
    for (int i = 0; i < tc; i++) {
        solve();
    }
}