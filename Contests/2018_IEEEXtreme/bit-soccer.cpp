#include <bits/stdc++.h>
using namespace std;

int n, q;
long long x;
long long p[100005];

int main() {
    scanf("%d", &n);
    for (int i=0; i<n; i++) {
        scanf("%lld", &p[i]);
    }
    scanf("%d", &q);
    while (q--) {
        scanf("%lld", &x);
        long long ans = 0;
        for (int i=0; i<n; i++) {
            bool bisa = true;
            for (int j=0; j<41; j++) {
                if (!(x & (1LL << j)) && (p[i] & (1LL << j))) bisa = false;
            }
            if (bisa) {
                ans |= p[i];
            }
        }
        printf("%s\n", (ans == x? "YES" : "NO"));
    }
}