#include<bits/stdc++.h>
using namespace std;

int na[100005];
int kn[100005];

int main() {
	int n,m;
	cin>>n>>m;
	while(n!=0 && m!=0) {
		for (int i=0; i<n; i++) {
			scanf("%d",&na[i]);
		}
		for (int j=0; j<m; j++) {
			scanf("%d",&kn[j]);
		}
		sort(na,na+n);
		sort(kn,kn+m);
		int res=0;
		int j=0;
		bool bisa=false;
		for (int i=0; i<n; i++) {
			if (j>=m) {
					cout<<"Loowater is doomed!"<<endl;
					bisa=true;
					break;
				}
			while (kn[j]<na[i]) {
				j++;
				if (j>=m) {
					cout<<"Loowater is doomed!"<<endl;
					bisa=true;
					break;
				}
			}
			if (bisa) break;
//			cout<<i<<" "<<j<<endl;
			res+=kn[j];
			j++;
		}
		if (!bisa) cout<<res<<endl;
		
		cin>>n>>m;
	}
}
