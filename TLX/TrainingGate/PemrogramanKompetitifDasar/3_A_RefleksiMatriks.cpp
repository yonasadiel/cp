#include<bits/stdc++.h>
using namespace std;

int main() {
	int barisa,barisb,koloma,kolomb;
	int isia[80][80], isib[80][80];
	
	scanf("%d %d",&barisa,&koloma);
	for (int r=1; r<=barisa; r++) {
		for (int c=1; c<=koloma; c++) {
			scanf("%d",&isia[r][c]);
		}
	}
	
	scanf("%d %d",&barisb,&kolomb);
	for (int r=1; r<=barisb; r++) {
		for (int c=1; c<=kolomb; c++) {
			scanf("%d",&isib[r][c]);
		}
	}
	
	
	//IDENTIK
	bool cek=true;
	for (int r=1; r<=barisb; r++) {
		for (int c=1; c<=kolomb; c++) {
			if (isia[r][c]!=isib[r][c]) cek=false;
		}
	}
	if(cek) {
		printf("identik\n"); return 0;
	}
	
	//HORISONTAL
	cek=true;
	for (int r=1; r<=barisb; r++) {
		for (int c=1; c<=kolomb; c++) {
			if (isia[r][c]!=isib[barisb-r+1][c]) cek=false;
		}
	}
	if(cek) {
		printf("horisontal\n"); return 0;
	}
	//DIAGONAL KANAN BAWAH
	cek=true;
	for (int r=1; r<=barisb; r++) {
		for (int c=1; c<=kolomb; c++) {
			if (isia[r][c]!=isib[c][r]) cek=false;
		}
	}
	if(cek) {
		printf("diagonal kanan bawah\n"); return 0;
	}
	//VERTIKAL
	cek=true;
	for (int r=1; r<=barisb; r++) {
		for (int c=1; c<=kolomb; c++) {
			if (isia[r][c]!=isib[r][kolomb-c+1]) cek=false;
		}
	}
	if(cek) {
		printf("vertikal\n"); return 0;
	}
	//DIAGONAL KIRI BAWAH
	cek=true;
	for (int r=1; r<=barisb; r++) {
		for (int c=1; c<=kolomb; c++) {
			if (isia[r][c]!=isib[kolomb-c+1][barisb-r+1]) cek=false;
		}
	}
	if(cek) {
		printf("diagonal kiri bawah\n"); return 0;
	}
		
	printf("tidak identik\n"); return 0;
}
