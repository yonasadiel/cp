#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define mp make_pair
#define pb push_back
#define pi acos(-1.0)
#define uint64 unsigned long long
#define FastSlowInput ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define debug if(true)
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

const int mod = 1e9 + 7;

const int maxn =2e5 + 5;

ll fac[maxn];

void factorize(){
	fac[0] = 1;
	for(int i=1;i<maxn;i++){
		fac[i] = (ll)i*fac[i-1];
		fac[i] %= mod;
	}
}

ll modPow(ll a, ll b){
	if(b == 0){return 1;}
	else{
		if(b%2 == 1){return a*modPow(a,b-1)%mod;}
		else{
			ll temp = modPow(a,b/2);
			return temp*temp%mod;
		}
	}
}

ll inv(ll a){
	return modPow(a,mod-2);
}

ll comb(ll a, ll b){
	ll ans = fac[a]*inv(fac[a-b]);
	// printf("ans: %lld %lld\n",ans, fac[a]);
	ans %= mod;
	ans *= inv(fac[b]);
	ans %= mod;
	return ans;
}

int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	factorize();

	ll ans = 0;
	int kotak = m + 1;
	for (int dua = 0; dua * 2 <= n; dua++) {
		int satu = n - 2 * dua;
		if (kotak >= satu + dua) {
			ans += (comb(kotak, dua) * comb(kotak - dua, satu)) % mod;
			ans %= mod;
		}
	}
	printf("%lld\n", (ans + mod) % mod);
	return 0;
};