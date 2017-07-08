#include<bits/stdc++.h>
using namespace std;

long long n,m;
int in;
long long colcnt[1005], colfi[1005], colla[1005];
long long rowcnt[1005], rowfi[1005], rowla[1005];
long long ret;

int main() {
	memset(colcnt,0,sizeof colcnt); memset(colfi,0,sizeof colfi); memset(colla,0,sizeof colla);
	memset(rowcnt,0,sizeof rowcnt); memset(rowfi,0,sizeof rowfi); memset(rowla,0,sizeof rowla);
	
	scanf("%I64d%I64d",&n,&m);
	for (int i=1; i<=n; i++) {
		for (int j=1; j<=m; j++) {
			scanf("%d",&in);
			if (in == 1) {
				// vertikal
				colcnt[j]++;
				colla[j] = i;
				if (colfi[j] == 0) {
					colfi[j] = i;
				}
				
				//horizontal
				rowcnt[i]++;
				rowla[i] = j;
				if (rowfi[i] == 0) {
					rowfi[i] = j;
				}
				
			}
		}
	}
	
	ret = 0;
	for (int i=1; i<=m; i++) {
	//	cout<<colcnt[i]<<" "<<colfi[i]<<" "<<colla[i]<<endl;
		if (colcnt[i] > 0)
		ret += (long long) 2*n - (colfi[i] - 1) - (n - colla[i]) - (2*colcnt[i]);
	}
	for (int i=1; i<=n; i++) {
		if (rowcnt[i] > 0)
		ret += (long long) 2*m - (rowfi[i] - 1) - (m - rowla[i]) - (2*rowcnt[i]);
	}
	
	printf("%I64d\n",ret);
	
}
