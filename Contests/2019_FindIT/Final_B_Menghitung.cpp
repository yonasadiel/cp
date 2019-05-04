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

ll lpow(ll a, ll b) {
	ll ans = 1LL;
	for (ll i=0; i<b; i++) ans *= a;
	return ans;
}

ll s(ll x) {
	ll ans = 0;
	while (x > 0) {
		ans += x % 10;
		x /= 10;
	}
	return ans;
}

int main() {
	set<ll> ans;
	ll a, b, c;
    scanf("%lld%lld%lld", &a, &b, &c);
	for (ll i=0; i<=100; i++) {
		ll x = lpow(i, a) * b + c;
		if (1 < x && x < 1000000000) {
			if (s(x) == i)ans.insert(x);
		}
	}
	printf("%d\n", ans.size());
	bool first = true;
	for (ll x : ans) {
		if (!first) printf(" ");
		printf("%lld", x);
		first = false;
	}
	printf("\n");
}