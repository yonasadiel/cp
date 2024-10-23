#include <cstdio>
#include <cstring>
#include <iostream>
#define MAXN 10000000
using namespace std;



bool primes[MAXN+5];
void sieve(long long n) {
    memset(primes, true, sizeof(primes));
    primes[0] = false;
    primes[1] = false;
    for (long long p=2; p*p<=n; p++) {
        if (primes[p]) {
            for (long long i=p*p; i<=n; i+=p)
                primes[i] = false;
        }
    }
}

long long arr[MAXN+5];
void precomp(int n) {
    memset(arr, 0, sizeof(arr));
    for (int i=1; i<=n; i++) {
        arr[i] = arr[i-1];
        if (i==5) arr[i]++;
        if (!primes[i]) { continue; }
        if (i > 4 && primes[i-2]) arr[i]++;
    }
}

void solve(int tc) {
    int n;
    scanf("%d", &n);
    printf("Case #%d: %lld\n", tc, arr[n]);
}

int main() {
    sieve(MAXN);
    precomp(MAXN);
    int t;
    scanf("%d", &t);
    for (int i=1; i<=t; i++) solve(i);
}
