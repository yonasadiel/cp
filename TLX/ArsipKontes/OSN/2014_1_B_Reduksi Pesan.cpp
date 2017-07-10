#include<bits/stdc++.h>
using namespace std;

char subsoal[100];
char kalimat[100005];
char baru[12];
int N,Q,mini,maks;
char terakhir;

int main() {
	scanf("%s",&subsoal);
	scanf("%d%d",&N,&Q);
	for (int i=0; i<=N; i++) {
		scanf("%c",&kalimat[i]);
	}
	while (Q--) {
		bool cek=true;
		scanf("%d%d",&mini,&maks);
		int hitung=1;
		baru[hitung]=kalimat[mini];
		terakhir=kalimat[mini];
		if (mini<=maks) {
			for (int i=mini+1; i<=maks; i++) {
	//			printf("%d %c %d\n",i,kalimat[i],hitung);
				if (kalimat[i]!=terakhir) {	
					terakhir=kalimat[i];
					hitung++;			
					if (hitung>=10) cek=false;
					if (cek) baru[hitung]=kalimat[i];
				}
			}
		} else {
			for (int i=mini+1; i>=maks; i--) {
	//			printf("%d %c %d\n",i,kalimat[i],hitung);
				if (kalimat[i]!=terakhir) {	
					terakhir=kalimat[i];
					hitung++;			
					if (hitung>=10) cek=false;
					if (cek) baru[hitung]=kalimat[i];
				}
			}
		}
		printf("%d",hitung);
		if (cek) {
			printf(" ");
			for (int i=1; i<=hitung; i++) {
				printf("%c",baru[i]);
			}
		}
		printf("\n");
	}
}
