#include<bits/stdc++.h>
using namespace std;

int nilai[2005];
int dp[2005][2005];
int n;

int ambil(int endas, int buntut) {
//	cout<<endas<<buntut<<umur<<endl;
	int umur=endas-buntut+n;
	if (dp[endas][buntut]!=-1) {
		return dp[endas][buntut];
	}
	if (endas==buntut) {
		dp[endas][buntut]=nilai[endas]*umur;
		return dp[endas][buntut];
	}
	dp[endas][buntut]=(max(nilai[endas]*umur+ambil(endas+1,buntut),
								 nilai[buntut]*umur+ambil(endas,buntut-1)));
	return dp[endas][buntut];			
}

int main() {
	memset(dp,-1,sizeof dp);
	scanf("%d",&n);
	for (int i=1; i<=n; i++) {
		scanf("%d",&nilai[i]);
	}
	printf("%d\n",ambil(1,n));
}
