#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[100005], b[100005], d[100005];
vector<pair<int, int> > c;

int main() {
    memset(d, -1, sizeof d);
    scanf("%d%d", &n, &m);
    for (int i=0; i<n; i++) {
        scanf("%d", &a[i]);
        c.push_back({a[i], i});
    }
    sort(c.begin(), c.end());

    int x = (n / m) * m;
    for (int i=0; i<m; i++) {
        b[i] = x;
        x++; if (x > n) x -= m;
    }
    for (pair<int, int> p : c) {
        d[p.second] = b[p.first];
        b[p.first] -= m;
    }
    bool bisa = true;
    for (int i=0; i<n; i++) {
        if (d[i] <= 0) bisa = false;
    }
    if (!bisa) {
        printf("-1\n");
    } else {
        for (int i=0; i<n; i++) {
            printf("%d%c", d[i], (i == n-1? '\n' : ' '));
        }
    }
}