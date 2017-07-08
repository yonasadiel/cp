#include <bits/stdc++.h>

int main() {
	
	int baris,kolom,matriks[105][105];
	int sirab,molok,skirtam[105][105];
	scanf("%d %d %d",&baris,&kolom,&molok);
	
	for (int i=0; i<baris; i++) {
		for (int j=0; j<kolom; j++) {
			scanf("%d",&matriks[i][j]);
		}
	}
	
	sirab=kolom;
	
	for (int i=0; i<sirab; i++) {
		for (int j=0; j<molok; j++) {
			scanf("%d",&skirtam[i][j]);
		}
	}		
	
	int barisirab,kolomolok,matrikskirtam[105][105];
	barisirab=baris;
	kolomolok=molok;
	int batas=kolom;
	memset(matrikskirtam,0,sizeof(matrikskirtam));
	
	for (int i=0; i<barisirab; i++) {
		for (int j=0; j<kolomolok; j++) {
				for (int k=0; k<batas; k++) {
					matrikskirtam[i][j]=matrikskirtam[i][j]+(matriks[i][k]*skirtam[k][j]);
				}
		}
	}
	
	
	for (int i=0; i<barisirab; i++) {
		for (int j=0; j<kolomolok; j++) {
			printf("%d",matrikskirtam[i][j]);
			if (j!=kolomolok-1) printf(" ");
		}
		printf("\n");
	}
	
	return 0;
}
