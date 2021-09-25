#include <iostream>
#include <cstdio>
using namespace std;

int n;
char s[1000000];

int tr(char cc) {
    if (cc == 'X') return 1;
    if (cc == 'O') return 2;
    return 3;
}

#define MOD 1000000007

void solve(int tc) {
    scanf("%d", &n);
    scanf("\n%s", s);

    int cc = 3;
    long long ans = 0, run = 0;
    int last[4];
    last[1] = -1;
    last[2] = -1;
    for (int i = 0; i < n; i++) {
        int ci = tr(s[i]);
        if (ci != 3) {
            if ((cc & ci) == 0) {
                // between i and last_x is F, they dont require to change
                run += last[3-ci] + 1;
            }
            last[ci] = i;
        }
        ans += run;
        run %= MOD;
        ans %= MOD;
        if (cc & ci) {
            cc = cc & ci;
        } else {
            cc = ci;
        }
        // printf("%c%d ", s[i], run);
    }
    printf("Case #%d: %lld\n", tc, ans);
}

int main() {
    int t;
    scanf("%d", &t);
    for (int i=1; i<=t; i++) solve(i);
}