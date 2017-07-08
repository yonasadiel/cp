#include<bits/stdc++.h>
using namespace std;

int n,m;
char peta[105][105];

int main() {
	scanf("%d",&n);
	while(n!=0) {
		scanf("%d",&m);
		for (int i=1; i<=n; i++) {
			for (int j=0; j<=m; j++) {
				scanf("%c",&peta[i][j]);
			}
		}
		
		int res=0;
		for (int i=1; i<=n; i++) {
			for (int j=i; j<=n; j++) {
				int last=1;
				int hitung=0;
				for (int k=1; k<=m; k++) {
					for(int l=i; l<=j; l++) {
						if (peta[l][k]=='0') {
							last=k+1;
							break;
						}
					}
					if (last!=k+1) {
						hitung++;
					} else {
						res+=(hitung*(hitung+1))/2;
//						cout<<(hitung*(hitung+1))/2;
						hitung=0;
					}
				}
				if (hitung!=0) {
					res+=(hitung*(hitung+1))/2;
//					cout<<(hitung*(hitung+1))/2;
					hitung=0;
				}
//				cout<<endl;
			}
		}
		printf("%d\n",res);
		scanf("%d",&n);

	}
}
