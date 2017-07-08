#define fi first
#define se second
#include<bits/stdc++.h>
using namespace std;

int n,m;
pair<int,pair<int,int> > jalan[100005];
int bapak[10005];

int caribapak(int anak) {
	if (bapak[anak]==anak) {
		return anak;
	} else {
		bapak[anak]=caribapak(bapak[anak]);
		return bapak[anak];
	}
}

int main() {
	scanf("%d%d",&n,&m);
	for (int i=0; i<n; i++) {
		bapak[i]=i;
	}
	
	for (int i=0; i<m; i++) {
		scanf("%d%d%d",&jalan[i].se.fi,&jalan[i].se.se,&jalan[i].fi);
	}
	sort(jalan,jalan+m);
	
	long long hasil=0;
	for (int i=0; i<m; i++) {
		int a=caribapak(jalan[i].se.fi);
		int b=caribapak(jalan[i].se.se);
		if (a!=b) {
			hasil+=(long long)jalan[i].fi;
			bapak[a]=b;
		}
	}
	
	cout<<hasil<<endl;
}
