#include <bits/stdc++.h>
using namespace std;

int r, c;

int quad(int rn, int cn) {
    if (rn <  r / 2 && cn <  c / 2) return 1;
    if (rn <  r / 2 && cn >= c / 2) return 2;
    if (rn >= r / 2 && cn <  c / 2) return 3;
    if (rn >= r / 2 && cn >= c / 2) return 4;
}

void solve() {
    int cnt[50][5];
    int cntmax[50];
    char** p;
    int** d;
    memset(cnt, 0, sizeof cnt);
    scanf("%d%d", &c, &r);
    p = (char**) malloc(r * sizeof(char*));
    d = (int**) malloc(r * sizeof(int*));
    for (int i=0; i<r; i++) {
        p[i] = (char*) malloc(c * sizeof(char));
        d[i] = (int*) malloc(c * sizeof(int));
        for (int j=0; j<c; j++) {
            cin >> p[i][j];
            cnt[p[i][j] - 'a'][quad(i, j)]++;
        }
    }
    for (int i = 0; i < 30; i++) {
        int getmax = 1;
        if (cnt[i][2] > cnt[i][getmax]) getmax = 2;
        if (cnt[i][3] > cnt[i][getmax]) getmax = 3;
        if (cnt[i][4] > cnt[i][getmax]) getmax = 4;
        cntmax[i] = getmax;
    }
    for (int i=0; i<r; i++) {
        for (int j=0; j<c; j++) {
            cout << p[i][j];
            cout << cntmax[p[i][j] - 'a'];
            if (j == c - 1) cout << "\n"; else cout << " ";
        }
    }

    for (int i = 0; i < r; i++) {
        free(p[i]);
        free(d[i]);
    }
    free(p);
    free(d);

}

int main() {
    int t;
    scanf("%d", &t);
    for (int i=1; i<=t; i++) {
        printf("%d\n", i);
        solve();
    }
}