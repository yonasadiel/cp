#include <bits/stdc++.h>
using namespace std;

int k[15];
long long exper, b;
vector<vector<long long> > v;

void brute(vector<long long>& poss, int pos, int hi) {
    if (exper > b) return;
    if (pos >= hi) {
        poss.push_back(exper);
    } else {
        for (int i = 0; i < v[pos].size(); i++) {
            exper += v[pos][i];
            brute(poss, pos + 2, hi);
            exper -= v[pos][i];
        }
    }
}

void solve() {
    long long x;
    int n;
    scanf("%lld%d", &b, &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &k[i]);
    }
    v.assign(n, vector<long long>());
    for (int i = 0; i < n; i++) {
        v[i].clear();
        for (int j = 0; j < k[i]; j++) {
            scanf("%lld", &x);
            v[i].push_back(x);
        }
    }
    sort(v.begin(), v.end(), [](const vector<long long>& a, const vector<long long>& b) {
        return a.size() < b.size();
    });
    vector<long long> d1, d2;
    exper = 0LL; brute(d1, 0, n);
    exper = 0LL; brute(d2, 1, n);
    fprintf(stderr, "d1=%d d2=%d\n", d1.size(), d2.size());
    sort(d1.begin(), d1.end());
    sort(d2.begin(), d2.end());

    int i2 = d2.size() - 1;
    long long ans = 0LL;
    for (int i1 = 0; i1 < d1.size(); i1++) {
        i2 = upper_bound(d2.begin(), d2.end(), b - d1[i1]) - d2.begin() - 1;

        if (i2 >= 0) ans = max(ans, d1[i1] + d2[i2]);
    }
    printf("%lld\n", ans);
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) solve();
}