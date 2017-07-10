#include<bits/stdc++.h>
using namespace std;

int r,c;
int pet[150][150];
int m=0;
int stat[20];
char kode[100005][20];

void input() {
	memset(pet,0,sizeof pet);
	scanf("%d%d",&r,&c);
	for (int i=0; i<r; i++) {
		for (int j=0; j<c; j++) {
			scanf("%d",&pet[i][j]);
		}
	}
	int a = 1; while (a<max(r,c)) a*=2; r = a; c = a;
	
}

void out() {
	printf("%d\n",m);
	for (int i=0; i<m; i++) {
		printf("%s\n",kode[i]);
	}
}

void pengodean(int ra, int rb, int ca, int cb, int d) {
	if (ra == rb) {
		if (pet[ra][ca] == 1) {
			kode[m][0] = '1';
			for (int i=0; i<d; i++) {
				kode[m][i+1] = stat[i] + '0';
			}
			m++;
		}			
	} else {
		bool ada;
		int ran,rbn,can,cbn;
		
		//all area
		ada = false;
		ran = ra; rbn = rb;
		can = ca; cbn = cb;
		for (int i=ran; i<=rbn; i++) {
			for (int j=can; j<=cbn; j++) {
				if (pet[i][j] == 0) ada = true;
			}
		}
		if (!ada) {
			kode[m][0] = '1';
			for (int i=0; i<d; i++) {
				kode[m][i+1] = stat[i] + '0';
			}
			m++;
		} else {
			//area 0
			ada = false;
			ran = ra; rbn = ra+(rb-ra+1)/2-1;
			can = ca; cbn = ca+(cb-ca+1)/2-1;
			for (int i=ran; i<=rbn; i++) {
				for (int j=can; j<=cbn; j++) {
					if (pet[i][j] == 1) ada = true;
				}
			}
			if (ada) {
				stat[d] = 0;
				pengodean(ran,rbn,can,cbn,d+1);
			}
			
			//area 1
			ada = false;
			ran = ra; rbn = ra+(rb-ra+1)/2-1;
			can = ca+(cb-ca+1)/2; cbn = cb;
			for (int i=ran; i<=rbn; i++) {
				for (int j=can; j<=cbn; j++) {
					if (pet[i][j] == 1) ada = true;
				}
			}if (ada) {
				stat[d] = 1;
				pengodean(ran,rbn,can,cbn,d+1);
			}
			
			//area 2
			ada = false;
			ran = ra+(rb-ra+1)/2; rbn = rb;
			can = ca; cbn = ca+(cb-ca+1)/2-1;
			for (int i=ran; i<=rbn; i++) {
				for (int j=can; j<=cbn; j++) {
					if (pet[i][j] == 1) ada = true;
				}
			}
			if (ada) {
				stat[d] = 2;
				pengodean(ran,rbn,can,cbn,d+1);
			}
			
			//area 3
			ada = false;
			ran = ra+(rb-ra+1)/2; rbn = rb;
			can = ca+(cb-ca+1)/2; cbn = cb;
			for (int i=ran; i<=rbn; i++) {
				for (int j=can; j<=cbn; j++) {
					if (pet[i][j] == 1) ada = true;
				}
			}if (ada) {
				stat[d] = 3;
				pengodean(ran,rbn,can,cbn,d+1);
			}
		}
	}
}


int main() {
	input();
	pengodean(0,r-1,0,c-1,0);
	out();
}
