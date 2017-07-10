#include<bits/stdc++.h>
using namespace std;

int r,c,k,panjang;
char matrik[105][105],gakepake;
char kalimat[105];
bool arah[8];

bool cari(int ro, int co) {
	//ke kanan
	bool sementara=true;
	for (int i=1; i<panjang; i++) {
		if (co+i<=c) {
			if (matrik[ro][co+i]!=kalimat[i]) {
				sementara=false;
				break;
			}
		} else {
			sementara=false;
			break;
		}
	}
	if (sementara) {
//		printf("(%d,%d) ke kanan\n",ro,co);
		return true;
	}
	//ke kiri
	sementara=true;
	for (int i=1; i<panjang; i++) {
		if (co-i>=1) {
			if (matrik[ro][co-i]!=kalimat[i]) {
				sementara=false;
				break;	
			}
		} else {
			sementara=false;
			break;
		}
	}
	if (sementara) {
//		printf("(%d,%d) ke kiri\n",ro,co);
		return true;
	}
	//ke atas
	sementara=true;
	for (int i=1; i<panjang; i++) {
		if (ro-i>=1) {
			if (matrik[ro-i][co]!=kalimat[i]) {
				sementara=false;
				break;
			}
		} else {
			sementara=false;
			break;
		}
	}
	if (sementara) {
//		printf("(%d,%d) ke atas\n",ro,co);
		return true;
	}
	//ke bawah
	sementara=true;
	for (int i=1; i<panjang; i++) {
		if (ro+i<=r) {
			if (matrik[ro+i][co]!=kalimat[i]) {
				sementara=false;
				break;
			}
		} else {
			sementara=false;
			break;
		}
	}
	if (sementara) {
//		printf("(%d,%d) ke bawah\n",ro,co);
		return true;
	}
	//ke kanan bawah
	sementara=true;
	for (int i=1; i<panjang; i++) {
		if (ro+i<=r && co+i<=c) {
			if (matrik[ro+i][co+i]!=kalimat[i]) {
				sementara=false;
				break;
			}
		} else {
			sementara=false;
			break;
		}
	}
	if (sementara) {
//		printf("(%d,%d) ke kanan bawah\n",ro,co);
		return true;
	}
	//ke kiri bawah
	sementara=true;
	for (int i=1; i<panjang; i++) {
		if (ro+i<=r && co-i>=1) {
			if (matrik[ro+i][co-i]!=kalimat[i]) {
				sementara=false;
				break;
			}
		} else {
			sementara=false;
			break;
		}
	}
	if (sementara) {
//		printf("(%d,%d) ke kiri bawah\n",ro,co);
		return true;
	}
	//ke kanan atas
	sementara=true;
	for (int i=1; i<panjang; i++) {
		if (ro-i>=1 && co+i<=c) {
			if (matrik[ro-i][co+i]!=kalimat[i]) {
				sementara=false;
				break;
			} 
		} else {
			sementara=false;
			break;
		}
	}
	if (sementara) {
//		printf("(%d,%d) ke kanan atas\n",ro,co);
		return true;
	}
	//ke kiri atas
	sementara=true;
	for (int i=1; i<panjang; i++) {
		if (ro-i>=1 && co-i>=1) {
				if (matrik[ro-i][co-i]!=kalimat[i]) {
				sementara=false;
				break;
			}
		} else {
			sementara=false;
			break;
		}
	}
	if (sementara) {
//		printf("(%d,%d) ke kiri atas\n",ro,co);
		return true;
	}
//	printf("tidak ada");
	return false;
	
}

int main() {
	scanf("%d%d",&r,&c);
	for (int i=1; i<=r; i++) {
		for (int j=1; j<=c; j++) {
			scanf("%c",&gakepake);
			scanf("%c",&matrik[i][j]);
//			printf("%c",matrik[i][j]);
		}
//		printf("\n");
	}
	scanf("%d",&k);
	bool ada;
	for (int i=0; i<k; i++) {
		ada=false;
		scanf("%s",&kalimat);
		panjang=strlen(kalimat);
		for (int j=1; j<=r; j++) {
			for (int k=1; k<=c; k++) {
				if (matrik[j][k]==kalimat[0]) {
					ada=cari(j,k);
				}
				if (ada) break;
			}
			if (ada) break;
		}
		for (int l=0; l<panjang; l++) {
			printf("%c",kalimat[l]);
		}
		if (ada) {
			printf(" Y\n");
		} else {
			printf(" T\n");
		}
	}
}
