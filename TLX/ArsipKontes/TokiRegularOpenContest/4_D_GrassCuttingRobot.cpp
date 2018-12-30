#include <bits/stdc++.h>
using namespace std;

int t, n, k;

int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &k);
        int g = __gcd(n, k);
        n /= g;
        k /= g;
        if (k > n) {
            printf("YES\n");
        } else if (k == 1) {
            if (n % 2 == 0 && n % 4 != 0) {
                printf("NO\n");
            } else {
                printf("YES\n");
            }
        } else {
            printf("YES\n");
        }
    }
}