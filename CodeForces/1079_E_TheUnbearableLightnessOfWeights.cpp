#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define MAXSUM 10000

int n;
int a[105];
long long dp[105][MAXSUM+5];
long long komb[105][105];

void debug() {
    for (int i=0; i<=n; i++) {
        for (int j=0; j<=10; j++) {
            printf("%lld ", dp[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void precompute() {
    komb[0][0] = 1LL;
    for (int i=1; i<105; i++) {
        for (int j=0; j<=i; j++) {
            komb[i][j] = 0LL;
            if (j < i) komb[i][j] += komb[i-1][j];
            if (j > 0) komb[i][j] += komb[i-1][j-1];
            komb[i][j] %= MOD;
            //printf("komb(%d, %d) = %lld\n", i, j, komb[i][j]);
        }
    }
}

int main() {
    precompute();
    scanf("%d", &n);
    for (int i=1; i<=n; i++) {
        scanf("%d", &a[i]);
    }

    int ans = 1;
    memset(dp, 0, sizeof dp);
    dp[0][0]++;
    for (int pos=1; pos<=n; pos++) {
        for (int length=100; length>=0; length--) {
            for (int sm=MAXSUM; sm>=0; sm--) {
                if (dp[length][sm] > 0) {
                    dp[length+1][sm + a[pos]] += dp[length][sm];
                    dp[length+1][sm + a[pos]] %= MOD;
                }
            }
        }
        //debug();
    }

    sort(a+1, a+n+1);
    int last = 1;
    for (int i=2; i<=n+1; i++) {
        if (i == n+1 || a[i] != a[i-1]) {
            int length = i-last;
            int el = a[last];
            last = i;

            for (int j=2; j<=length; j++) {
                long long kk = komb[length][j];
                if (dp[j][el*j] == kk) {
                    ans = max(ans, j);
                }
            }
        }
    }
    int cnt_dst = 1;
    for (int i=2; i<=n; i++) { if (a[i] != a[i-1]) cnt_dst++; }
    if (cnt_dst == 2) {
        int sum1 = a[1], sum2=0;
        for (int i=2; i<=n; i++) { if (a[i] == a[1]) sum1 += a[i]; sum2 += a[i]; }
        if (sum1 != sum2) {
            printf("%d\n", n);
            return 0;
        }
    }

    printf("%d\n", ans);
}
