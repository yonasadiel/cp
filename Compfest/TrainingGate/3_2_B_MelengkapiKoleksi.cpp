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

ll lcm(ll a, ll b) { return a/__gcd(a,b)*b; }

int n, q, x;
int a[100005];

int main() {
    scanf("%d%d", &n, &q);
    for (int i=0; i<n; i++) {
        scanf("%d", &a[i]);
    }
    sort(a, a+n);

    while (q--) {
        scanf("%d", &x);
        if (binary_search(a, a+n, x)) {
            printf("ada\n");
        } else {
            printf("tidak ada\n");
        }
    }
}