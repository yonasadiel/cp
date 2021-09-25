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

#define MOD 1000000007LL

void solve(int tc) {
    scanf("%d", &n);
    scanf("\n%s", s);

    int cc = 3;
    long long ans = 0, run = 0, cnt = 0, snt = 0, size = 0;
    long long last[4], first[4];
    last[1] = -1;
    last[2] = -1;
    first[1] = -1;
    first[2] = -1;
    bool first_1 = true;
    for (int i = 0; i < n; i++) {
        if (s[i] == '.') {
            long long trun = run, tans = ans, tcnt = cnt, tsnt = snt;
            long long wbdg = 0, hbdg = 0;
            if (first[1] != -1 && first[2] != -1) {
                if (first_1 && cc == 2) {
                    hbdg = last[2];
                    wbdg = (size - first[1] + 1 + MOD) % MOD;
                } else if (!first_1 && cc == 1) {
                    hbdg = last[1];
                    wbdg = (size - first[2] + 1 + MOD) % MOD;
                }
            }
            if (last[1] != -1) { last[1] += size; last[1] %= MOD; }
            if (last[2] != -1) { last[2] += size; last[2] %= MOD; }

            ans += tans;                ans %= MOD;
            ans += (tsnt * size) % MOD; ans %= MOD;
            ans += (hbdg * wbdg) % MOD; ans %= MOD;
            ans += (trun * size) % MOD; ans %= MOD;

            run += trun;                run %= MOD;
            run += (tcnt * size) % MOD; run %= MOD;
            run += hbdg;                run %= MOD;

            cnt += hbdg > 0 ? 1 : 0;    cnt %= MOD;
            cnt += tcnt;                cnt %= MOD;

            snt += (tcnt * size) % MOD; snt %= MOD;
            snt += wbdg;                snt %= MOD;
            snt += tsnt;                snt %= MOD;

            cc = cc;
            size *= 2;                  size %= MOD;
        } else {
            int ci = tr(s[i]);
            if (ci != 3) {
                if ((cc & ci) == 0) {
                    if (last[3-ci] == -1) exit(1);
                    run += last[3-ci]; run %= MOD;
                    cnt++;             cnt %= MOD;
                }
                last[ci] = (size + 1) % MOD;
            }
            ans += run; ans %= MOD;
            snt += cnt; snt %= MOD;

            cc = (cc & ci) ? (cc & ci) : ci;
            size++;     size %= MOD;

            if (ci != 3 && first[ci] == -1) {
                if (first[1] == -1 && first[2] == -1) {
                    first_1 = ci == 1;
                }
                first[ci] = size;
            }
        }
        // printf("%c|size=%lld|cnt=%lld|snt=%lld|run=%lld|ans=%lld\n", s[i], size, cnt, snt, run, ans);
    }
    printf("Case #%d: %lld\n", tc, ans);
}

int main() {
    int t;
    scanf("%d", &t);
    for (int i=1; i<=t; i++) solve(i);
}