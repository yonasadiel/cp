#include <cstdio>
#include <algorithm>
#define harga first
#define banyak second
#define ll long long
#define pll pair<ll,ll>
using namespace std;

int n;
long long m;
pll c[100005];
long long ret;

bool cmp(pll le, pll ri) {
	return le.harga < ri.harga;
}

int main() {
	scanf("%d%lld",&n,&m);
	for (int i=0; i<n; i++) { scanf("%lld%lld", &c[i].harga, &c[i].banyak); }
	sort(c, c+n, cmp);
	ll ret = 0;
	for (int i=0; i<n && m>0; i++) {
		ll get = min(m/c[i].harga, c[i].banyak);
		ret += get;
		m -= get * c[i].harga;
	}
	printf("%lld\n",ret);
}