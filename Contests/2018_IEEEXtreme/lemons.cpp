#include <bits/stdc++.h>
using namespace std;

long long n, m, s;

int main() {
    scanf("%lld%lld%lld", &n, &m, &s);
    int l = 2, r = n;
    long long ans = 0;
    int last = 1;
    while (l <= r) {
        //cout << l << " " << r << endl;
        int mi = (l + r) / 2;
        ans += m * abs(last - mi);
        ans += s;
        if ((mi-1) - l + 1 > r - mi + 1) {
            r = mi-1;
        } else {
            l = mi+1;
        }
        last = mi;
    }
    printf("%lld\n", ans);
}