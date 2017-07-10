#include<bits/stdc++.h>
using namespace std;

bool petak[130][130];

string alamat[10000];

bool bagi_empat(string alamat) {
	if (strlen(alamat)==1+p) {
		return petak
	}
}

int main() {
	memset(petak,false,sizeof petak);
	int n,m;
	scanf("%d%d",&n,&m);
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			scanf("%d",&masuk);
			if (masuk==1) {
				petak[i][j]=true;
			}
		}
	}
	
	int p=max(n,m);
	for (int k=0; k<9; k++) {
		if (maks<(1<<k)+1) {
			p=k;
		}
	}
	bagi_empat(1);
}
