#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int n, maks, semak[1005],kase=1;
int dp[1005][1005];

int ambil(int posisi,int diambil) {
	if (dp[posisi][diambil]!=-1) {
		return dp[posisi][diambil];
	}
	if (posisi>n) {
		dp[posisi][diambil]=diambil;
		return diambil;
	}
	int temp=diambil+semak[posisi];
	if (temp<=maks) {
		dp[posisi][diambil]=max(ambil(posisi+1,diambil),ambil(posisi+2,temp));
	} else {
//		cout<<"b"<<endl;
		dp[posisi][diambil]=ambil(posisi+1,diambil);
	}
	return dp[posisi][diambil];
	
	
}

int main() {
	scanf("%d",&kase);
	for (int k=1; k<=kase; k++){
		memset(dp,-1,sizeof dp);
		scanf("%d%d",&n,&maks);
		for (int i=1; i<=n; i++) {
			scanf("%d",&semak[i]);
		}
		printf("Scenario #%d: %d\n",k,ambil(1,0));
	}
	
}
