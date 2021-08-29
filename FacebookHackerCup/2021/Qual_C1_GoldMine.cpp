#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int n, a, b;
int val[100];
int dp[100];
vector<int> adj[100];

int traverse(int x, int p) {
    int l = 0;
    for (int cc : adj[x]) {
        if (cc == p) continue;
        dp[cc] = traverse(cc, x);
        l = max(l, dp[cc]);
    }
    return l + val[x];
}

void solve(int tc) {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &val[i]);
        adj[i].clear();
    }
    for (int i = 0; i < n - 1; i++) {
        scanf("%d%d", &a, &b);
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dp[0] = traverse(0, -1);

    vector<int> childs_val;
    for (int cc : adj[0]) {
        childs_val.push_back(dp[cc]);
    }
    sort(childs_val.begin(), childs_val.end());

    int ans = val[0];
    for (int i = 0; i < min(2, (int)childs_val.size()); i++) {
        ans += childs_val[childs_val.size() - 1 - i];
    }

    printf("Case #%d: %d\n", tc, ans);
}

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        solve(i + 1);
    }
}