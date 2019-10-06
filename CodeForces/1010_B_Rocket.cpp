#include <bits/stdc++.h>
using namespace std;

int m, n;
int pattern[50];

int main() {
    scanf("%d%d", &m, &n);
    for (int i=0; i<n; i++) {
        printf("1\n");
        fflush(stdout);
        scanf("%d", &pattern[i]);
        if (pattern[i] == 0) {
            exit(0);
        }
    }

    int lo = 2;
    int hi = m;
    int cnt = 0;
    while (lo < hi) {
        int mi = (lo + hi) >> 1;
        printf("%d\n", mi);
        fflush(stdout);

        int ans;
        scanf("%d", &ans);
        if (pattern[cnt] == -1) ans = -ans;
        cnt = (cnt + 1) % n;
        if (ans == 1) {
            lo = mi + 1;
        } else if (ans == -1) {
            hi= mi - 1;
        } else {
            exit(0);
        }
    }
    printf("%d\n", lo);
}