#include <bits/stdc++.h>
using namespace std;

int n, m; long long kk;
vector<vector<long long> >a;
vector<vector<vector<long long> > > dp;
#define FT 4

int main() {
    scanf("%d%d%lld", &n, &m, &kk);
    for (int i=0; i<min(n, m); i++) {
        vector<long long> v;
        for (int j=0; j<max(n, m); j++) {
            v.push_back(0LL);
        }
        a.push_back(v);
    }

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (n < m) {
                scanf("%lld", &a[i][j]);
            } else {
                scanf("%lld", &a[j][i]);
            }
        }
    }
    // for (int i=0; i<n; i++) {
    //     for (int j=0; j<m; j++) {
    //         printf("%lld ", a[i][j]);
    //     }
    //     printf("\n");
    // }
    for (int i=0; i<FT; i++) {
        vector<vector<long long> > v1;
        for (int j=0; j<min(n, m); j++) {
            vector<long long> v2;
            for (int k=0; k<min(n, m); k++) {
                v2.push_back(-1);
            }
            v1.push_back(v2);
        }
        dp.push_back(v1);
    }
    for (int i=0; i<n+m-1; i++) {
        for (int j=0; j<min(n, m); j++) {
            for (int k=0; k<min(n, m); k++) {
                if (i == 0) {
                    dp[i % FT][j][k] = 0LL;
                } else if (i >= j && i >= k) {
                    long long nn = dp[(i-1+FT) % FT][j][k];
                    if (j > 0 && k > 0) { nn = max(nn, dp[(i-1+FT) % FT][j-1][k-1]); }
                    if (j > 0) { nn = max(nn, dp[(i-1+FT) % FT][j-1][k]); }
                    if (k > 0) { nn = max(nn, dp[(i-1+FT) % FT][j][k-1]); }

                    if (j == k) nn += a[j][i-j] + (a[j][i-j] ^ kk);
                    else nn += a[j][i-j] + a[k][i-k];
                    dp[i % FT][j][k] = nn;
                }
            }
        }
    }

    printf("%lld\n", dp[(n+m-2) % FT][min(n, m)-1][min(n, m)-1]);
}