#define fi first
#define se second
#include<bits/stdc++.h>
using namespace std;

int kasus,n;
string peta[505];
int hasil[505][505];
queue<pair<int, pair<int,int> > > antri;

int main() {
	scanf("%d",&kasus);
	while (kasus--) {
		memset(hasil,-1,sizeof hasil);
		
		scanf("%d",&n);
		for (int i=0; i<n; i++) {

			cin>>peta[i];


		}
		
		antri.push(make_pair(0,make_pair(0,0)));
		if (peta[0][0]=='*') hasil[0][0]++;
		
		while (!antri.empty()) {
			pair<int,pair<int,int> > skg=antri.front();
			antri.pop();
//			cout<<skg.se.fi<<" "<<skg.se.se<<" "<<skg.fi<<endl;
			if (skg.se.fi<n && skg.se.se<peta[n-1].length()) {
				if (peta[skg.se.fi][skg.se.se]=='*' && hasil[skg.se.fi][skg.se.se]<skg.fi+1) {
					hasil[skg.se.fi][skg.se.se]=skg.fi+1;
					antri.push(make_pair(skg.fi+1,make_pair(skg.se.fi+1,skg.se.se)));
					antri.push(make_pair(skg.fi+1,make_pair(skg.se.fi,skg.se.se+1)));
				}
				if (peta[skg.se.fi][skg.se.se]=='.' && hasil[skg.se.fi][skg.se.se]<skg.fi) {
					hasil[skg.se.fi][skg.se.se]=skg.fi;
					antri.push(make_pair(skg.fi,make_pair(skg.se.fi+1,skg.se.se)));
					antri.push(make_pair(skg.fi,make_pair(skg.se.fi,skg.se.se+1)));
				}
			}
		}
		
		printf("%d\n",hasil[n-1][peta[n-1].length()-1]);
		
	}
}
