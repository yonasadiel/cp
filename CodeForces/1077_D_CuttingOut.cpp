#include <bits/stdc++.h>
using namespace std;

int n, k;
int s[200005];
int cnt[200005];

int guess(int x) {
    int ans = 0;
    for (int i=1; i<=200000; i++) {
        ans += cnt[i] / x;
    }
    return (ans >= k);
}

int main() {
    memset(cnt, 0, sizeof cnt);

    scanf("%d%d", &n, &k);
    for (int i=0; i<n; i++) {
        scanf("%d", &s[i]);
        cnt[s[i]]++;
    }

    int lo = 1, hi = 200000, ans = 1;
    while (lo <= hi) {
        int mi = (lo + hi) / 2;
        if (guess(mi)) {
            ans = mi;
            lo = mi + 1;
        } else {
            hi = mi - 1;
        }
    }

    int kk = 0;
    for (int i=1; i<=200000; i++) {
        for (int j=0; j<cnt[i] / ans && kk <k; j++, kk++) {
            if (kk != 0) printf(" ");
            printf("%d", i);
        }
    }
    printf("\n");
}