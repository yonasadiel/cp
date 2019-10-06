#include <bits/stdc++.h>
using namespace std;

int n;
string s;
int l[1000005]; bool vl[1000005];
int r[1000005]; bool vr[1000005];
int cnt, ans;

int solve() {
    cin >> s;
    for (int i=0; i<n; i++) {
        l[i] = (i == 0 ? 0 : l[i-1]) + (s[i] == '(' ? 1 : -1);
        vl[i] = (i == 0 ? true : vl[i-1]) && (l[i] >= 0);
    }
    for (int i=n-1; i>=0; i--) {
        r[i] = (i == n-1 ? 0 : r[i+1]) + (s[i] == ')' ? 1 : -1);
        vr[i] = (i == n-1 ? true : vr[i+1]) && (r[i] >= 0);
    }
    cnt = 0;
    for (int i=1; i<=n-2; i++) {
        // printf("-%d:%d:%d-", i, vl[i-1], vr[i+1]);
        if (vl[i-1] && vr[i+1]) {
            if (s[i] == '(') {
                if (l[i-1] - 1 == r[i+1]) {
                    cnt++;
                    // printf("=%d=", i);
                }
            } else {
                if (l[i-1] + 1 == r[i+1]) {
                    cnt++;
                    // printf("=%d=", i);
                }
            }
        }
    }
    if (n > 1 && s[0] == ')' && vr[1] && r[1] == 1) cnt++;
    if (n > 1 && s[n-1] == '(' && vl[n-2] && l[n-2] == 1) cnt++;
    printf("%d\n", cnt);
}

int main () {
    while (scanf("%d", &n) == 1) {
        solve();
        if (cin >> ans) {
            if (ans != cnt) {
                printf(" salah coi\n");
            }
        }
    }
}