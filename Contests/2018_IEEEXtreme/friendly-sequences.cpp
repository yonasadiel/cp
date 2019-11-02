#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

int n;
int b[100005];

long long dp[2][2005][2005];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &b[i]);
    }
    for (int pos = 0; pos < n; pos++) {
        for (int maxsum = 0; maxsum <= b[pos]; maxsum++) {
            for (int maxnum = 0; maxnum <= (pos + 1 < n? b[pos + 1] : 2000); maxnum++) {
                long long &ret = dp[pos % 2][maxsum][maxnum];
                if (pos == 0) {
                    ret = min(maxsum, maxnum) + 1;
                } else {
                    ret = 0;
                    for (int i = 0; i <= min(maxsum, maxnum); i++) {
                        ret += dp[(pos - 1) % 2][min(maxsum - i, b[pos - 1])][i];
                        ret %= MOD;
                    }
                }
            }
        }
    }

    printf("%lld\n", dp[(n - 1) % 2][b[n - 1]][b[n - 1]]);
}