#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;

pair<string,string> a[100005];
string c;

int main() {
	int n,m;
	scanf("%d%d",&n,&m);
	for (int i=0; i<n; i++) {
		cin>>a[i].fi>>a[i].se;
	}
	for (int i=0; i<m; i++) {
		cin>>c;
		int awal=0,akhir=n-1;
		int found = -1;
		
		while (awal<=akhir && found==-1) {
	//		cout<<awal<<" "<<akhir<<endl;
			int tengah = (awal+akhir)/2;
			if (a[tengah].fi == c) {
				found = tengah;
			} else if (a[tengah].fi < c) {
				awal = tengah+1;
			} else {
				akhir = tengah-1;
			}
		}
		
		if (found == -1) {
			cout<<"NIHIL"<<endl;
		} else {
			cout<<a[found].se<<endl;
		}
	}
}
