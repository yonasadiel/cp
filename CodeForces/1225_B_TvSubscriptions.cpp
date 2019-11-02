#include <bits/stdc++.h>
using namespace std;

int t;
int n, k, d;
int a[2000005];
int b[200005];
int x;

int main() {
    scanf("%d", &t);
    memset(a, 0, sizeof (a));
    for (int tc = 0; tc < t; tc++) {
        scanf("%d%d%d", &n, &k, &d);
        for (int i = 0; i < n; i++) {
            scanf("%d", &b[i]);
        }
        int cnt = 0;
        int ans = d;
        for (int i = 0; i < n; i++) {
            if (a[b[i]] == 0) cnt++;
            a[b[i]]++;

            if (i - d >= 0) {
                a[b[i - d]]--;
                if (a[b[i - d]] == 0) {
                    cnt--;
                }
            }

            if (i >= d - 1) {
                ans = min(ans, cnt);
            }
        }
        for (int i = 0; i < n; i++) {
            a[b[i]] = 0;
        }
        printf("%d\n", ans);
    }
}