#include<bits/stdc++.h>
using namespace std;

int angka[100005];

int main() {
	int n,m;
	long long jumlah=0,maksim=-1e17;
	scanf("%d%d",&n,&m);
	for (int i=0; i<m-1; i++) {
		scanf("%d",&angka[i]);
		jumlah+=angka[i];
	}
	for (int i=m-1; i<n; i++) {
		scanf("%d",&angka[i]);
		jumlah+=angka[i];
		maksim=max(maksim,jumlah);
		jumlah-=angka[i-m+1];
	}
	cout<<maksim<<endl;
}
