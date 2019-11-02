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
#define debug if(false)
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef pair<ii,int> iii;
typedef vector<ii> vii;

const int maxn = 2e5 + 5;

int main(){
	int n,i,j;
	scanf("%d",&n);
	int a[maxn];
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	printf("1");
	debug printf("\n");
	set<iii> s;
	set<iii>::iterator it;
	s.insert(iii(ii(-inf, a[0]), 2));
	debug printf("pushawal: %d %d %d\n",-inf, a[0], 2);
	if(a[0]+1 <= inf){
		s.insert(iii(ii(a[0]+1, inf), 2));	
		debug printf("pushawal: %d %d %d\n",a[0]+1, inf, 2);
	}
	
	for(i=1;i<n;i++){
		int bil = a[i];
		it = s.upper_bound(iii(ii(bil,0),0));
		if(it == s.end()){
			it--;
		}
		iii pertama = *it;
		if(pertama.first.first > bil){
			it--;
		}
		debug printf("pertama %d %d %d\n",pertama.first.first, pertama.first.second, pertama.second);
		
		iii pas = *it;
		s.erase(pas);

		ii par = pas.first;
		int tinggi = pas.second;
		int awal = par.first, akhir = par.second;
		debug printf("bil: %d awal: %d akhir: %d tinggi: %d\n",bil, awal, akhir, tinggi);
		printf(" %d",tinggi);
		debug printf("\n");
		s.insert(iii(ii(awal, bil), tinggi+1));
		if(bil+1 <= akhir){
			s.insert(iii(ii(bil+1, akhir), tinggi+1));	
		}
		
		debug printf("push: %d %d %d dan %d %d %d\n",awal, bil, tinggi+1, bil+1, akhir, tinggi+1);
		
	}
	printf("\n");
	return 0;
};