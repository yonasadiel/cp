#include <bits/stdc++.h>
using namespace std;

int n, a, b, c;
char s[100005];
char t[100005];

void solve() {
    scanf("%d", &n);
    scanf("%d%d%d", &a, &b, &c);
    scanf(" %s", s);
    int win = 0;
    for (int i = 0; i < n; i++) {
        t[i] = ' ';
        if      (s[i] == 'R' && b > 0) { t[i] = 'P'; b--; win++; }
        else if (s[i] == 'P' && c > 0) { t[i] = 'S'; c--; win++; }
        else if (s[i] == 'S' && a > 0) { t[i] = 'R'; a--; win++; }
    }
    for (int i = 0; i < n; i++) {
        if (t[i] == ' ') {
            if      (s[i] == 'R' && a > 0) { t[i] = 'R'; a--; }
            else if (s[i] == 'P' && b > 0) { t[i] = 'P'; b--; }
            else if (s[i] == 'S' && c > 0) { t[i] = 'S'; c--; }
        }
    }
    for (int i = 0; i < n; i++) {
        if (t[i] == ' ') {
            if      (s[i] == 'R' && c > 0) { t[i] = 'S'; c--; }
            else if (s[i] == 'P' && a > 0) { t[i] = 'R'; a--; }
            else if (s[i] == 'S' && b > 0) { t[i] = 'P'; b--; }
        }
    }
    if (win >= (n + 1) / 2) {
        printf("YES\n");
        for (int i = 0; i < n; i++) printf("%c", t[i]); printf("\n");
    } else {
        printf("NO\n");
    }
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        solve();
    }
}