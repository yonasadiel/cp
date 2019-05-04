#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pii pair<int, int>
#define MOD 1000000007
#define vi vector<int>
using namespace std;

const ll mod = 1e9;

int main() {
	int t;
    scanf("%d", &t);
    while(t--){
    	int n;
    	scanf("%d", &n);
    	ll pem = 12;
    	ll ans = 1;
    	ll now = 1LL * n * n;
    	ll gcd = __gcd(now, pem);
    	now /=gcd;
    	now %= mod;
    	ans = (ans * now) % mod;
    	now = 1LL * (n+1) * (n+1);
    	gcd = __gcd(now, pem);
    	now /=gcd;
    	now %= mod;
    	ans = (ans * now) % mod;
    	now = 2LL * n * n + 2 *n - 1;
    	gcd = __gcd(now, pem);
    	now /=gcd;
    	now %= mod;
    	ans = (ans * now) % mod;
    	printf("%lld\n", ans);
	}
}