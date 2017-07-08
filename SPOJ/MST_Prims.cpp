#define fi first
#define se second
#include<bits/stdc++.h>
using namespace std;

int n,m;
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >antrian_vip;
vector <pair<int,int> > jalan[100005];
bool sudah[500005];

int main() {
	memset(sudah,false,sizeof sudah);
	scanf("%d%d",&n,&m);
	int a,b,c;
	for (int i=0; i<m; i++) {
		scanf("%d%d%d",&a,&b,&c);
		jalan[a].push_back(make_pair(c,b));
		jalan[b].push_back(make_pair(c,a));
	}
	
	for (int i=0; i<jalan[1].size(); i++) {
		antrian_vip.push(make_pair(jalan[1][i].fi,jalan[1][i].se));
	}
	sudah[1]=true;
	
	long long hasil=0;
	while(!antrian_vip.empty()) {
		pair<int,int> kur=antrian_vip.top();
		antrian_vip.pop();
		if (!sudah[kur.se]) {
			hasil+=kur.fi;
			sudah[kur.se]=true;
			for (int i=0; i<jalan[kur.se].size(); i++) {
				antrian_vip.push(make_pair(jalan[kur.se][i].fi,jalan[kur.se][i].se));
			}
		}
	}
	
	cout<<hasil<<endl;
}
