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

int fact[10005];
const ll mod = 1000000004;

void addfact(int val){
	int sq = sqrt(val);
	for(int i=2;i<=sq && val > 1;++i){
		int cnt = 0;
		while(val % i == 0){
			cnt++;
			val /= i;
		}
		fact[i] += cnt;
	}
	if(val > 1){
		fact[val]++;
	}
}

void decfact(int val){
	int sq = sqrt(val);
	for(int i=2;i<=sq && val > 1;++i){
		int cnt = 0;
		while(val % i == 0){
			cnt++;
			val /= i;
		}
		fact[i] -= cnt;
	}
	if(val > 1){
		fact[val]--;
	}
}

ll modpow(ll a, int b){
	ll res = 1;
	for(;b;b>>=1){
		if(b & 1){
			res = res * a % mod;
		}
		a = a* a % mod;
	}
	return res;
}

ll combin(int len, const vector<pair<int, int> > & x){
	memset(fact, 0, sizeof fact);
	for(int i=len;i>1;--i){
		addfact(i);
	}
	for(int i=0;i<x.size();++i){
		for(int j=2;j<=x[i].fi;++j){
			decfact(j);
		}
	}
	ll ans = 1;
	for(int i=2;i<10000;++i){
		ans = ans * modpow(i, fact[i]) % mod;
	}
	return ans;
}

char s[10002];

int main() {
	int n;
    scanf("%d", &n);
    scanf("%s", s);
    vector<pair<int, int> > a, b;
    int tota = 0;
    int totb = 0;
    int suma = 0;
    int sumb = 0;
    for(int i=0;i<n;++i){
    	if(s[i] == 'S'){
    		tota++;
		}
		else{
			totb++;
		}
    	if(i > 0){
    		if(s[i] != s[i-1]){
    			if(s[i-1]=='S'){
    				a.pb({suma, i != suma});
    				suma = 0;
    				sumb++;
				}
				else{
					b.pb({sumb, i != sumb});
					sumb = 0;
					suma++;
				}
			}
			else{
				if(s[i] == 'S'){
					suma++;
				}
				else{
					sumb++;
				}
			}
		}
		else{
			if(s[i] == 'S'){
				suma++;
			}
			else{
				sumb++;
			}
		}
	}
	if(suma > 0){
    	a.pb({suma, 0});
	}
	else if(sumb > 0){
    	b.pb({sumb, 0});
	}
	ll ansa, ansb = 1;
	ansa = combin(tota, a) % mod;
	ansb = combin(totb, b) % mod;
	for(int i=0;i<a.size();++i){
		if(a[i].se == 1){
			ansa = (ansa * modpow(2, a[i].fi - 1) )% mod;
		}
	}
	for(int i=0;i<b.size();++i){
		if(b[i].se == 1){
			ansb = (ansb * modpow(2, b[i].fi - 1) )% mod;
		}
	}
	printf("%lld %lld\n", ansa, ansb);
	return 0;
}