#include<bits/stdc++.h>
using namespace std;

int kase;
int m,n;
int x[1005],y[1005];
int depe[1005][1005];

int playdp(int cntx, int cnty) {
//	cout<<cntx<<" "<<cnty<<endl;
	if (depe[cntx][cnty]!=-1) {
		return depe[cntx][cnty];
	}
	if (cntx==m+1 && cnty==n+1) {
		depe[cntx][cnty]=0;
		return depe[cntx][cnty];
	}
	if (cntx==m+1) {
		depe[cntx][cnty]=cntx*y[n-cnty]+playdp(cntx,cnty+1);
		return depe[cntx][cnty];
	}
	if (cnty==n+1) {
		depe[cntx][cnty]=cnty*x[m-cntx]+playdp(cntx+1,cnty);
		return depe[cntx][cnty];
	}
	depe[cntx][cnty]=min(cntx*y[n-cnty]+playdp(cntx,cnty+1),cnty*x[m-cntx]+playdp(cntx+1,cnty));
	return depe[cntx][cnty];
}

int main() {
	scanf("%d",&kase);
	while(kase--) {
		memset(depe,-1,sizeof depe);

		scanf("%d%d",&m,&n);
		m--; n--;
		for (int i=0; i<m; i++) {
			scanf("%d",&x[i]);
		}
		for (int i=0; i<n; i++) {
			scanf("%d",&y[i]);
		}
		sort(x,x+m);
		sort(y,y+n);
		
		printf("%d\n",playdp(1,1));
		
		
	}
}
