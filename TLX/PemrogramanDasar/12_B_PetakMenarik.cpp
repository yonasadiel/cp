#include<bits/stdc++.h>
using namespace std;

int main() {
	int n,m,x,ar[105][105];
	memset(ar,-1,sizeof ar);
	scanf("%d%d%d",&n,&m,&x);
	for (int i=1; i<=n; i++) {
		for (int j=1; j<=m; j++) {
			scanf("%d",&ar[i][j]);
		}
	}
	
	bool found=false;
	int ns=0,ms=0;
	for (int j=1; j<=m; j++) {
		for (int i=1; i<=n; i++) {
			if (abs(ar[i-1][j]*ar[i][j-1]*ar[i][j+1]*ar[i+1][j])==x) {
				ns=i;
				ms=j;
				found=true;
				break;
			}
		}
		if (found) break;
	}
	printf("%d %d\n",ns,ms);
}
