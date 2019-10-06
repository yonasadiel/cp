#include <bits/stdc++.h>
using namespace std;

int main() {
    long long a,b,ans=0;
    scanf("%I64d%I64d", &a, &b);
    while (a > 0 && b > 0) {
        if (a > b) {
            ans += a / b;
            a %= b;
        } else {
            ans += b / a;
            b %= a;
        }
    }
    printf("%I64d\n", max(a,b));
}