#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

int n;
int a[100005];
long long dp[1000005];
vector<int> fact[1000005];

int main() {
    scanf("%d", &n);
    //int ma = 0;
    for (int i=1; i<=1000000; i++) {
        for (int j=i; j<=1000000; j+=i) {
            fact[j].push_back(i);
        }
        // ma = max(ma, (int) fact[i].size());
    }
    //printf("max factor = %d\n", ma);
    for (int i=0; i<n; i++) {
        scanf("%d", &a[i]);
    }

    memset(dp, 0, sizeof dp);
    long long ans = 0LL;
    dp[0] = 1LL;
    for (int pos=0; pos<n; pos++) {
        for (int i=fact[a[pos]].size()-1; i>=0; i--) {
            int val = fact[a[pos]][i];
            //if (a[pos] % val == 0) {
                dp[val] += dp[val-1];
                dp[val] %= MOD;
            //}
            //printf("dp[%d]=%d, ans=%d\n", val, dp[val], ans);
        }
    }
    for (int i=1; i<=1000000; i++) {
        ans += dp[i];
        ans %= MOD;
    }
    printf("%lld\n", ans);
    //printf("done\n");
}