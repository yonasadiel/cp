#include<bits/stdc++.h>
#define fi first
#define se second.first
#define th second.second.first
#define fo second.second.second
using namespace std;

pair<int,pair<int,pair<int,string> > > pet[100];
int t,n,m;
string dicari,temp;

bool komp(pair<int,pair<int,pair<int,string> > > a, pair<int,pair<int,pair<int,string> > > b) {
	if (a.fi != b.fi) {
		return a.fi > b.fi;
	} else if (a.se != b.se) {
		return a.se > b.se;
	} else if (a.th != b.th) {
		return a.th > b.th;
	} else {
		while(1);
	}
}

int main() {
	scanf("%d",&t);
	while(t--) {
		scanf("%d%d",&n,&m);
		cin >> dicari;
		for (int i=0; i<n; i++) {
			cin >> pet[i].fo >> pet[i].th >> pet[i].se >> pet[i].fi;
		}
		sort(pet,pet+n,komp);

		bool lolos=false;
		for (int i=0; i<m; i++) {
			if (pet[i].fo == dicari) lolos = true;
		}

		if (lolos) cout<<"YA"<<endl;
		else cout<<"TIDAK"<<endl;
	}
}
