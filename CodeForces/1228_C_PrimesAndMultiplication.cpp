#include <bits/stdc++.h>
#define MOD 1000000007
#define ll long long
using namespace std;

ll n, x;

ll fastpow(ll a, ll b) {
    ll ans = 1LL;
    ll c = a;
    for (int i = 0; i < 64; i++) {
        if (b & (1LL << i)) {
            ans *= c;
            ans %= MOD;
        }
        c *= c;
        c %= MOD;
    }
    return ans;
}


#define MAXPRIME 100000
vector<ll> primes;
bitset<MAXPRIME+1> is_composite;

void sieve() {
    is_composite.reset();

    for (long long i = 2; i <= MAXPRIME; i++) {
        if (!is_composite[i]) primes.push_back(i);
        for (int j = 0; j < primes.size() && i * primes[j] <= MAXPRIME; j++) {
            is_composite[i * primes[j]] = 1;
            if (i % primes[j] == 0) break;
        }
    }

}

bool isPrime(ll x) {
    for (ll i = 2LL; i * i <= x; i++) {
        if (x % i == 0) return false;
    }
    return true;
}

int main() {
    sieve();
    while (cin >> x >> n) {
        set<ll> p;

        for (ll pt : primes) {
            if (x % pt == 0) {
                p.insert(pt);
                while (x % pt == 0) x /= pt;
            }
        }

        if (x > 1LL) p.insert(x);

        // for (ll px : p) cout << px << " "; cout << endl;

        ll ans = 1LL;
        for (ll px : p) {
            ll r = px;
            while (r <= n) {
                // cout << r << endl;
                ans *= fastpow(px, n / r);
                ans %= MOD;
                if (n / px < r) break;
                r *= px;
            }
        }

        printf("%lld\n", ans);
    }
}