#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n;
bool menang[400];
string e[400];
char ans[1000];

bool rec(int nround) {
    int r = 0, p = 0, s = 0;
    for (int i = 0; i < n; i++) {
        if (!menang[i]) {
            int ci = nround % e[i].length();
            if (e[i][ci] == 'R') r++;
            if (e[i][ci] == 'P') p++;
            if (e[i][ci] == 'S') s++;
        }
    }
    if (r + p == 0) {
        ans[nround] = 'R'; ans[nround + 1] = '\0'; return 1;
    } else if (r + s == 0) {
        ans[nround] = 'S'; ans[nround + 1] = '\0'; return 1;
    } else if (p + s == 0) {
        ans[nround] = 'P'; ans[nround + 1] = '\0'; return 1;
    } else if (r > 0 && p > 0 && s > 0) {
        return 0;
    } else {
        if (r == 0) {
            ans[nround] = 'S';
            for (int i = 0; i < n; i++) {
                int ci = nround % e[i].length();
                if (!menang[i] && e[i][ci]== 'P') menang[i] = 1;
            }
            return rec(nround + 1);
        } else if (s == 0) {
            ans[nround] = 'P';
            for (int i = 0; i < n; i++) {
                int ci = nround % e[i].length();
                if (!menang[i] && e[i][ci]== 'R') menang[i] = 1;
            }
            return rec(nround + 1);
        } else if (p == 0) {
            ans[nround] = 'R';
            for (int i = 0; i < n; i++) {
                int ci = nround % e[i].length();
                if (!menang[i] && e[i][ci]== 'S') menang[i] = 1;
            }
            return rec(nround + 1);
        }
    }
}

void solve(int tc) {
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> e[i];
    }
    memset(menang, 0, sizeof menang);

    printf("Case #%d: ", tc);
    if (rec(0)) {
        printf("%s\n", ans);
    } else {
        printf("IMPOSSIBLE\n");
    }
}

int main() {
    int t;
    scanf("%d", &t);
    for (int i=1; i<=t; i++) {
        solve(i);
    }
}