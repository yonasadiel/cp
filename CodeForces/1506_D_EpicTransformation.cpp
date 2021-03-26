#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;

bool desc(pair<int, int> a, pair<int, int> b) {
    return a.first > b.first;
}

void solve() {
    int n, x;
    map<int, int> m;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        m[x]++;
    }
    vector<pair<int, int> > v;
    for (auto it : m) {
        v.push_back(make_pair(it.second, it.first));
    }
    sort(v.begin(), v.end(), desc);
    int ans = 0;
    if (v.front().first * 2 > n) {
        ans = v.front().first * 2 - n;
    } else if (n & 1) {
        ans = 1;
    }
    printf("%d\n", ans);
}

int main() {
    int tc;
    scanf("%d", &tc);
    for (int i = 0; i < tc; i++) {
        solve();
    }
}