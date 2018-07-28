#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define mp make_pair
using namespace std;

ll a[100005];

int main() {
    int n;
    ll x = 0;
    ll sum = 0;
    scanf("%d", &n);
    for (int i=0; i<n; i++) {
        scanf("%lld", &a[i]);
        sum += a[i];
        if (a[i] > 0) x = max(x, a[i]+i);
    }

    int cnt = 0;
    bool last = false;
    for (int i=0; i<min((ll) n, x); i++) {
        if (a[i] == x-i) {
            last = false;
        } else {
            if (!last || (last && a[i-1] == x-i)) {
                cnt++;
            }
            last = true;
        }
    }
    if (x > n && a[n-1] >= x-n) { cnt++; }

    if (cnt > 1) {
        x += 2;
    }

    printf("%lld\n", x*(x+1)/2-sum);
}