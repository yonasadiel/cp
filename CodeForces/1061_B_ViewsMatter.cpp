#include <bits/stdc++.h>
using namespace std;

int n, m;
long long a[100005];

int main() {
    long long su = 0;
    scanf("%d%d", &n, &m);
    for (int i=0; i<n; i++) {
        scanf("%lld", &a[i]);
        su +=a[i];
    }
    sort(a, a+n);

    long long ans = 0;
    long long covered = 0;
    for (int i=0; i<n; i++) {
        if (covered == a[i]) {
            ans++;
        } else {
            ans++;
            covered++;
        }
    }
    if (covered < a[n-1]) ans += a[n-1] - covered;
    printf("%lld\n", su-ans);
}