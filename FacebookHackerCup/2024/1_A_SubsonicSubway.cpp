#include <cstdio>
using namespace std;

long long a[1000005], b[1000005];

void solve(int tc) {
    int n;
    long long mi=0, ma=0;
    scanf("%d", &n);
    for (long long i=0; i<n; i++) {
        scanf("%lld%lld", &a[i], &b[i]);
        if ((i+1)*b[ma] > (ma+1)*b[i]) { ma = i; }
        if ((i+1)*a[mi] < (mi+1)*a[i]) { mi = i; }
    }
    if ((ma+1)*a[mi] <= (mi+1)*b[ma]) {
        printf("Case #%d: %.8lf\n", tc, double(ma+1)/b[ma]);
        // printf("%lf %lld %lld\n", double(mi+1)/a[mi], ma, mi);
    } else {
        printf("Case #%d: -1\n", tc);
    }
}

int main() {
    int t;
    scanf("%d", &t);
    for (int i=1; i<=t; i++) {
        solve(i);
    }
}
