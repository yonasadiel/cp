#include <bits/stdc++.h>
using namespace std;

int n, k;
int cnt[40];

int solve() {
    memset(cnt, 0, sizeof cnt);
    int cur = 0, p = 0;
    for (int i=0; i<32; i++) {
        if ((1 << i) & n) {
            cnt[i]++;
            cur++;
            p = i;
        }
    }

    if (cur > k) {
        printf("NO\n");
        return 0;
    }
    int i = p;
    while (cur < k && i >= 1) {
        if (cnt[i] > 0) {
            int tam = min(cnt[i], k - cur);
            cnt[i] -= tam;
            cnt[i - 1] += 2 * tam;
            cur += tam;
        } else {
            i--;
        }
    }
    if (cur == k) {
        bool first = true;
        printf("YES\n");
        for (i=0; i<32; i++) {
            for (int j=0; j<cnt[i]; j++) {
                if (!first) printf(" ");
                first = false;
                printf("%d", 1 << i);
            }
        }
        printf("\n");
    } else {
        printf("NO\n");
    }
}

int main () {
    while (scanf("%d%d", &n, &k) == 2) {
        solve();
    }
}