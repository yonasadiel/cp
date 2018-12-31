#include <bits/stdc++.h>
using namespace std;

long long mpd(long long n) {
    for(long long i=2; i<=n; i++) {
        if (n %i == 0) return i;
        if (i >= 200000) return n;
    }
}

int main() {
    long long n;
    scanf("%lld", &n);
    long long cnt = 1;
    n -= mpd(n);
    cnt += n / 2;
    printf("%lld\n", cnt);
}