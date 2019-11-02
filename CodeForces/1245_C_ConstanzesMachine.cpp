#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

int n;
char s[100005];
long long ans[100005];

int main() {
    scanf("%s", s);
    n = strlen(s);

    for (int i = 0; i < n; i++) {
        if (s[i] == 'm' || s[i] == 'w') {
            printf("0\n");
            return 0;
        }
        if (i == 0) {
            ans[i] = 1LL;
        } else {
            ans[i] = ans[i - 1];
            if (s[i] == s[i - 1] && (s[i] == 'n' || s[i] == 'u')) {
                ans[i] += i < 2 ? 1LL : ans[i - 2];
                ans[i] %= MOD;
            }
        }
    }
    printf("%lld\n", ans[n - 1]);
}