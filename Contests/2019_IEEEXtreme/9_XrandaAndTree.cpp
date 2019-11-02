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
typedef pair<ii,int> iii;
typedef vector<ii> vii;

class UnionFind{
private: 
	vi rank,p,setSize;
	int numset,i;
public:
	UnionFind(int n){
		numset=n; setSize.assign(n,1); rank.assign(n,0); p.assign(n,0);
		for(i=0;i<n;i++){p[i]=i;}
	}

	int findSet(int i){return (p[i]==i) ? i : (p[i]=findSet(p[i]));}
	bool isSameSet(int i, int j){return findSet(i)==findSet(j);}
	void unionSet(int i, int j){
		if(!isSameSet(i,j)){
			numset--;
			int x=findSet(i), y=findSet(j);
			if(rank[x] > rank[y]){p[y]=x; setSize[x]+=setSize[y];}
			else{
				p[x]=y;
				setSize[y]+=setSize[x];
				if(rank[x]==rank[y]){rank[y]++;}
			}
		}
	}
	int numDisjointSet(){return numset;}
	int sizeSetOf(int i){return setSize[findSet(i)];}
};

int main(){
	int n,i,j;
	scanf("%d",&n);
	iii a[n+1];
	for(i=0;i<n-1;i++){
		scanf("%d %d %d",&a[i].first.first, &a[i].first.second, &a[i].second);
	}
	sort(a,a+n-1,[](iii a, iii b){
		return a.second < b.second;
	});
	UnionFind UF(n+1);
	ll mod = 1e9 + 7;
	ll ans = 0;
	for(i=0;i<n-1;i++){
		int u = a[i].first.first, v = a[i].first.second, w = a[i].second;
		// printf("u: %d v: %d w: %d\n",u,v,w);
		int ukuran1 = UF.sizeSetOf(u), ukuran2 = UF.sizeSetOf(v);
		ll jawab = (ll)ukuran2*ukuran1;
		jawab %= mod;
		jawab *= (ll)w;
		jawab %= mod;
		ans += jawab;
		ans %= mod;
		UF.unionSet(u,v);
	}
	printf("%lld\n",ans);
	return 0;
};//d