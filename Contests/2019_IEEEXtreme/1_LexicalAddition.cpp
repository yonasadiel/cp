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
typedef vector<ll> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

bool isBetween(ll n, ll a, ll b){
	return n>=a && n <= b;
}

bool isCan(int mid, ll n, ll a, ll b, ll& maks, ll& minim){
	maks = (n+(mid-1))/mid;
	minim = n/mid;
	if(isBetween(maks, a, b) && isBetween(minim, a, b)){
		return true;
	}else{
		return false;
	}
}

int main(){
	ll n,a,b, minim, maks;
	while(scanf("%lld %lld %lld",&n,&a,&b)!=EOF){
		int kiri = 1, kanan = 100000, mid, ans = -1;
		while(kiri <= kanan){
			mid = (kiri+kanan)/2;
			ll tempmaks = (n+(mid-1))/mid;
			ll tempminim = n/mid;
			if(tempminim < a){
				kanan = mid-1;
			}else if(tempmaks > b){
				kiri = mid+1;
			}else{
				ans = mid;
				kanan = mid-1;
				maks = tempmaks;
				minim = tempminim;
			}
			
		}

		int i,j;
		if(ans == -1){
			printf("NO\n");
			continue;
		}
		//udah dapet
		vi ar(100001);
		for(i=0;i<ans;i++){
			ar[i] = a;
		}
		ll sisa = n - a*ans;
		int idx = ans-1;
		while(sisa){
			ll minimal = min(sisa, b-ar[idx]);
			ar[idx] += minimal;
			sisa -= minimal;
			idx--;
		}
		printf("YES\n");
		for(i=0;i<ans;i++){
			if(i){printf(" ");}
			printf("%lld",ar[i]);
		}
		printf("\n");
	}
	
	
	return 0;
};