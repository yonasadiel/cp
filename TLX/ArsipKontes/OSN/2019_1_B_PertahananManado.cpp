#include <bits/stdc++.h>
#define start second.first
#define end first
#define price second.second
using namespace std;

int n, m;
long long s;
pair<int, pair<int, long long> > o[200005];
long long dp[200005];
priority_queue<pair<long long, int> > skip; // <price to skip to end, popped position>

int main() {
    scanf("%d%d%lld", &n, &m, &s);
    for (int i = 0; i < m; i++) {
        scanf("%d%d%d", &o[i].start, &o[i].end, &o[i].price);
    }
    sort(o, o + m);

    int i_o = m - 1;
    dp[n + 1] = 0LL;
    for (int i = n; i >= 0; i--) {
        while (i_o >= 0 && o[i_o].end == i) {
            skip.push({- (o[i_o].price + dp[i + 1]), o[i_o].start});
            i_o--;
        }

        while (!skip.empty() && skip.top().second > i) {
            skip.pop();
        }

        dp[i] = s + dp[i + 1];
        if (!skip.empty()) {
            dp[i] = min(dp[i], -skip.top().first);
        }
        // printf("dp[%d] = %lld\n", i, dp[i]);
    }
    printf("%lld\n", dp[1]);
}