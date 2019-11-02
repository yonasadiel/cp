#include <bits/stdc++.h>
using namespace std;

int n;
int a[100005];

void solve() {
    scanf("%d", &n);
    int ans = n+1;
    for (int i=0; i<n; i++) {
        scanf("%d", &a[i]);
        if (a[i] != -1 && a[i] != i+1) {
            int per = max(i - a[i] + 1, 1);
            if (ans == n+1) ans = per;
            ans = __gcd(per, ans);
        }
        //printf("%d %d\n", i, ans);
    }

    bool bisa = false;
    for (int i=0; i<n; i++) {
        if (a[i] != -1) bisa = true;
    }
    if (!bisa) {
        printf("inf\n");
        return;
    }

    bisa = true;
    for (int i=0; i<n; i++) {
        if (a[i] != -1 && a[i] != (i % ans) + 1) {
            bisa = false;
            //printf("%d %d\n", i, ans);
        }
    }
    if (bisa) printf("%d\n", ans);
    else printf("impossible\n");
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        solve();
    }
}