#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define mp make_pair
using namespace std;

int main() {
    int n, r, v, w;
    double ans = 0;
    scanf("%d%d%d", &n ,&r, &v);
    for (int i=0; i<n; i++) {
        scanf("%d", &w);
        if (w == v) {
            printf("-1\n");
            return 0;
        } else {
            ans = max(ans, r*1.0/abs(w-v));
        }
    }
    printf("%.9lf\n", ans);
}