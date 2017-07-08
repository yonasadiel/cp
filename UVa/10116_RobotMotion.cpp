#include<bits/stdc++.h>
using namespace std;

char peta[1005][1005];
int jarak[1005][1005];

int main() {
		int r,c,rn,cn;
		cin>>r>>c>>cn;
	while (r>0 && c>0 && cn>0) {
		memset(jarak,-1,sizeof jarak);
		rn=1;
		for (int i=1; i<=r; i++) {
			for (int j=0; j<=c; j++) {
				scanf("%c",&peta[i][j]);
			}
		}
		jarak[rn][cn]=1;
		while(true) {
			int re=rn, ce=cn;
			if (peta[rn][cn]=='N') rn--; else
			if (peta[rn][cn]=='S') rn++; else 
			if (peta[rn][cn]=='W') cn--; else
			if (peta[rn][cn]=='E') cn++;
			if (rn<1 || rn>r || cn<1 || cn>c) {
				cout<<jarak[re][ce]<<" step(s) to exit"<<endl;
				break;
			}
			if (jarak[rn][cn]==-1) {
				jarak[rn][cn]=jarak[re][ce]+1;
			} else {
				cout<<jarak[rn][cn]-1<<" step(s) before a loop of "<<jarak[re][ce]-jarak[rn][cn]+1<<" step(s)"<<endl;
				break;
			}
		}	
		cin>>r>>c>>cn;
	}
	
}
