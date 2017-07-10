#include<bits/stdc++.h>
using namespace std;

int r,c,rt,ct;
int pet[150][150];
int m=0;
int stat[20];
char kode[100005][20];

void penerjemahan(int pos, int ra, int rb, int ca, int cb, int d) {
	if (strlen(kode[pos]) <= d) {
		for (int i=ra; i<=rb; i++) {
			for (int j=ca; j<=cb; j++) {
				pet[i][j] = 1;
			}
		}
	} else {
		int ran,rbn,can,cbn;
		if (kode[pos][d] == '0') {
			ran = ra; rbn = ra+(rb-ra+1)/2-1;
			can = ca; cbn = ca+(cb-ca+1)/2-1;
		} else if (kode[pos][d] == '1') {
			ran = ra; rbn = ra+(rb-ra+1)/2-1;
			can = ca+(cb-ca+1)/2; cbn = cb;
		} else if (kode[pos][d] == '2') {
			ran = ra+(rb-ra+1)/2; rbn = rb;
			can = ca; cbn = ca+(cb-ca+1)/2-1;
		} else if (kode[pos][d] == '3') {
			ran = ra+(rb-ra+1)/2; rbn = rb;
			can = ca+(cb-ca+1)/2; cbn = cb;
		}
		penerjemahan(pos,ran,rbn,can,cbn,d+1);
	}
}

void input() {
	memset(pet,0,sizeof pet);
	scanf("%d",&m);
	for (int i=0; i<m; i++) {
		scanf("%s",kode[i]);
	}
	scanf("%d%d",&r,&c);
	rt = r; ct = c;
	int a = 1; while (a<max(r,c)) a*=2; r = a; c = a;
	for (int i=0; i<m; i++) {
		penerjemahan(i,0,r-1,0,c-1,1);
	}
}

void out() {
	for (int i=0; i<rt; i++) {
		for (int j=0; j<ct; j++) {
			printf("%d",pet[i][j]);
			if (j==ct-1) printf("\n");
			else printf(" ");
		}
	}
}


int main() {
	input();
	out();
}
