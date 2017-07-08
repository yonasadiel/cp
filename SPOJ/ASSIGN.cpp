#include<bits/stdc++.h>
using namespace std;

#define ll long long

int tugas[100][100];
ll dp[(2<<20)+1];
int n;

ll beritugas(int mask) {
	int pos=__builtin_popcount(mask);
//	if(pos==11)
//	cout << pos<< ' '<< mask<<endl;
	//masuk beritugas(0,0)
	if (mask == ((1<<n)-1)) {
		return 1;
	}

	ll &ret = dp[mask];
	if (ret!=-1) return ret;
	ret++;
	for (int i=0; i<n; i++) {
		if (!(mask&(1<<i)) && tugas[i][pos]==1) {
			ret+=beritugas(mask|(1<<i));
		}
	}
	return ret;
}

void ulang() {
	scanf("%d",&n);
	memset(dp,-1,sizeof dp);
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			scanf("%d",&tugas[i][j]);
		}
	}
	printf("%lld\n",beritugas(0));
	
}

int main() {
	int kase;
	scanf("%d",&kase);
	while (kase--) {
		ulang();
	}
	return 0;
}
