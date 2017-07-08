#include<bits/stdc++.h>
using namespace std;

int in,im,ik;
long long dp[60][60][60];

long long BC(int n, int k, int m) {
//	cout << n << " " << k << " " << m <<endl;
	
	if (dp[n][k][m]!=-1) {
//		cout << dp[n][k][m] <<endl;
		return dp[n][k][m];
	} 
	if (k<1) {
		dp[n][k][m]=0;
	} else {
		if (m<1) {
			dp[n][k][m]=0;
		} else {
			if ((n<1)&&(k==1)) {
		//		cout <<"oke"<<endl;
				dp[n][k][m]=1;
			} else {
				if (n<1) {
					dp[n][k][m]=0;
				} else {
					if (n==1) {
						dp[n][k][m]=BC(n-1,k,m);
					} else {
						dp[n][k][m]=BC(n-1,k,m-1)+BC(n-1,k-1,im);						
					}		
				}
						
			}
		}		
	}
	
	return dp[n][k][m];
}

int main() {

	while(scanf("%d %d %d",&in,&ik,&im)!=EOF) {	
	memset(dp,-1,sizeof dp);
		printf("%lld\n",BC(in,ik,im));
	}
	return 0;
}
