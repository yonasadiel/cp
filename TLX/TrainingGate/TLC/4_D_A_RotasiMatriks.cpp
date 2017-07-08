#include<bits/stdc++.h>
using namespace std;

int ms[80][80], md[80][80];
int r,c;

int main() {
	memset(ms,-1,sizeof ms);
	memset(md,-1,sizeof md);
	scanf("%d%d",&r,&c);
	for (int i=1; i<=r; i++) {
		for (int j=1; j<=c; j++) {
			scanf("%d",&ms[i][j]);
		}
	}
	scanf("%d%d",&r,&c);
	for (int i=1; i<=r; i++) {
		for (int j=1; j<=c; j++) {
			scanf("%d",&md[i][j]);
		}
	}
	
	bool periksa;
	//0
	periksa=true;
	for (int i=1; i<=r; i++) {
		for (int j=1; j<=c; j++) {
			if (md[i][j]!=ms[i][j]) {
				periksa=false;
			}
		}
		if (!periksa) break;
	}
	
	if (periksa) {
		printf("0\n");
		return 0;
	}
	
	//90
	periksa=true;
	for (int i=1; i<=r; i++) {
		for (int j=1; j<=c; j++) {
			if (md[i][j]!=ms[r+1-j][i]) {
				periksa=false;
			}
		}
		if (!periksa) break;
	}
	
	if (periksa) {
		printf("90\n");
		return 0;
	}
	
	//180
	periksa=true;
	for (int i=1; i<=r; i++) {
		for (int j=1; j<=c; j++) {
			if (md[i][j]!=ms[r+1-i][c+1-j]) {
				periksa=false;
			}
		}
		if (!periksa) break;
	}
	
	if (periksa) {
		printf("180\n");
		return 0;
	}
	
	//270
	periksa=true;
	for (int i=1; i<=r; i++) {
		for (int j=1; j<=c; j++) {
			if (md[i][j]!=ms[j][c+1-i]) {
				periksa=false;
			}
		}
		if (!periksa) break;
	}
	
	if (periksa) {
		printf("270\n");
		return 0;
	}
	
	printf("tidak sama\n");
	return 0;
}
