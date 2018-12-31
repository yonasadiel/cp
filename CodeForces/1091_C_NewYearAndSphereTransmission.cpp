#include <bits/stdc++.h>
using namespace std;

long long n;
vector<long long> factor, ans;

int main() {
    scanf("%lld", &n);
    // O(sqrt(N))
    for (long long i=1; i*i <= n; i++) {
        if (n % i == 0) {
            factor.push_back(i);
            factor.push_back(n / i);
        }
    }
    for (long long f : factor) {
        // 1, 1 + f, ...., n - f + 1
        ans.push_back(n / f * (1 + n - f + 1) / 2);
    }

    sort(ans.begin(), ans.end());
    for (int i = 0; i<ans.size(); i++) {
        if (i == 0 || ans[i] != ans[i-1]) {
            if (i > 0) printf(" ");
            printf("%lld", ans[i]);
        }
    }
    printf("\n");
}