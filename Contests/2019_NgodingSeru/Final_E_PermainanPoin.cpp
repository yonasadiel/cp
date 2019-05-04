#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pii pair<int, int>
#define mp make_pair
#define MOD 1000000007
using namespace std;

int r, c, b;
ll dp[202][202][400];

int main() {
    scanf("%d%d%d", &r, &c, &b);
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            for (int k = 0; k <= b; k++) {
                if (i == 0 && j == 0 && k == 0) {
                    dp[i][j][k] = 1;
                } else if (i == 0 && j == 0) {
                    dp[i][j][k] = 0;
                } else {
                    dp[i][j][k] = 0;
                    if (i > 0) dp[i][j][k] += dp[i - 1][j][k];
                    if (j > 0) dp[i][j][k] += dp[i][j - 1][k];
                    if (i > 0 && j > 0) dp[i][j][k] += MOD - dp[i - 1][j - 1][k];
                    if (k > 0 && !(i == r - 1 && j == c - 1)) {
                        if (i > 0) dp[i][j][k] += dp[i - 1][j][k - 1];
                        if (j > 0) dp[i][j][k] += dp[i][j - 1][k - 1];
                        if (i > 0 && j > 0) dp[i][j][k] += MOD - dp[i - 1][j - 1][k - 1];
                    }
                    dp[i][j][k] %= MOD;
                }
            }
        }
    }
    printf("%lld\n", dp[r-1][c-1][b]);
}
