#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define mp make_pair
#define pii pair<int, int>
using namespace std;

const int dr[] = {0, 1, -1, 0, 1, 1, -1, -1};
const int dc[] = {1, 0, 0, -1, 1, -1, 1, -1};

bool in_bound(pii _p, int _max_fi, int _max_se) {
    return _p.fi >= 0 && _p.fi < _max_fi && _p.se >= 0 && _p.se < _max_se;
}

int n, m;
int e[30];
int cur;
bool bisa;

void find(int pos) {
    if (cur == m) bisa = true;
    if (pos == n) return;

    find(pos+1);
    cur += e[pos];
    find(pos+1);
    cur -= e[pos];
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i=0; i<n; i++) {
        scanf("%d", &e[i]);
    }

    bisa = false;
    cur = 0;
    find(0);

    if (bisa) printf("bisa\n");
    else printf("tidak bisa\n");
}