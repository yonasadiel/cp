#include <bits/stdc++.h>
#define MOD 1000000007
#define ll long long
using namespace std;

ll fpow(ll base, ll to) {
    if (to <= 0) return 1LL;
    if (to == 1) return base;
    ll ans = fpow(base, to / 2);
    ans *= ans;
    ans %= MOD;
    if (to&1) ans *= base; ans %= MOD;
    return ans;
}

ll solve(int num_of_ones, int num_of_zeros) {
    ll ans = fpow(2, num_of_ones) - 1LL;

    ans += ans * (fpow(2, num_of_zeros) - 1);
    return ans % MOD;
}

int n, q;
char s[100005];
int no1[100005], no0[100005];

int main() {
    scanf("%d%d\n", &n, &q);
    scanf("%s", s);
    no1[0] = no0[0] = 0;
    for (int i=0; i<n; i++) {
        no1[i+1] = no1[i] + (s[i] == '1'? 1 : 0);
        no0[i+1] = no0[i] + (s[i] == '0'? 1 : 0);
    }
    for (int i=0; i<q; i++) {
        int l, r;
        scanf("%d%d", &l, &r);
        printf("%lld\n", solve(no1[r] - no1[l-1], no0[r] - no0[l-1]));
    }
}