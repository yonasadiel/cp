#include <bits/stdc++.h>
using namespace std;

int n, m;
long long a[1005][1005];

int main() {
    scanf("%d%d", &n, &m);

    for (int i=0; i<n; i++) {
        printf("? %d 1\n", i+1);
        fflush(stdout);
        scanf("%lld", &a[i][0]);
    }

    for (int j=1; j<m; j++) {
        printf("? 1 %d\n", j+1);
        fflush(stdout);
        scanf("%lld", &a[0][j]);
    }

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (i > 0 && j > 0) {
                a[i][j] = a[0][j] ^ a[i][0] ^ a[0][0];
            }
        }
    }

    long long ans = 0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            ans += a[i][j];
        }
    }
    printf("! %lld\n", ans);
    fflush(stdout);
}

// a1 ^ a2 = a1 ^ b1 ^ a2 ^ b1