#include <bits/stdc++.h>
using namespace std;

int n, m;
pair<int, int> ts[200005];
vector<pair<int, int> > stim;
vector<pair<int, int> > etim;

int main() {
    scanf("%d%d", &n, &m);
    for (int i=1; i<=n; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        ts[i] = {a, b};
        stim.push_back({ a, i });
        etim.push_back({ b, i });
    }
    sort(stim.begin(), stim.end());
    sort(etim.begin(), etim.end());

    for (int i = 1; i <= n; i++) {
        int ans = n - 1;
        ans -= lower_bound(etim.begin(), etim.end(), make_pair(ts[i].first, 0)) - etim.begin() - 1;
        ans -= n - (upper_bound(stim.begin(), stim.end(), make_pair(ts[i].second, n)) - stim.begin()) + 1;
        printf("%d\n", ans);
    }
}