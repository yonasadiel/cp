#include<bits/stdc++.h>
using namespace std;

int n,h[2015][2015],masukkan,indikator,indeksp;
int psatu[2015],pduwa[2015],ptiga[2015],indeksh[2015];


int main() {
	memset(h, -1, sizeof h);
	memset(indeksh, 0,sizeof indeksh);
	scanf("%d",&n);
	for(int i=1; i<=n; i++) {
		scanf("%d",&masukkan);
		h[masukkan][indeksh[masukkan]]=i;
		indeksh[masukkan]++;
	}
	indeksp=1;
	indikator=1;
	for (int i=1; i<=2000; i++) {
		if (h[i][0]==-1) continue;
		if (indeksh[i]==0) continue;
		if (indeksh[i]==1) {
			psatu[indeksp]=h[i][0];
			pduwa[indeksp]=h[i][0];
			ptiga[indeksp]=h[i][0];
			indeksp++;
		}
		if (indeksh[i]==2) {
			if (indikator!=2) {
				psatu[indeksp]=h[i][0];
				pduwa[indeksp]=h[i][1];
				ptiga[indeksp]=h[i][0];
				psatu[indeksp+1]=h[i][1];
				pduwa[indeksp+1]=h[i][0];
				ptiga[indeksp+1]=h[i][1];						
			} else {
				psatu[indeksp]=h[i][0];
				pduwa[indeksp]=h[i][0];
				ptiga[indeksp]=h[i][1];
				psatu[indeksp+1]=h[i][1];
				pduwa[indeksp+1]=h[i][1];
				ptiga[indeksp+1]=h[i][0];				
			}
			indeksp+=2;
			indikator*=2;
		}
		if (indeksh[i]>=3) {
			for (int k=0; k<indeksh[i]; k++) {
				psatu[indeksp]=h[i][k];
				pduwa[indeksp]=h[i][(k+1)%indeksh[i]];
				ptiga[indeksp]=h[i][(k+2)%indeksh[i]];
				indeksp++;
			}
			indikator*=indeksh[i];
		}
		
	}
	
	if (indikator==1 || indikator==2) {
		printf("NO\n");
	} else {
		printf("YES\n");
		for (int i=1; i<n; i++) {
			printf("%d ",psatu[i]);
		}
		printf("%d\n",psatu[n]);
		
		for (int i=1; i<n; i++) {
			printf("%d ",pduwa[i]);
		}
		printf("%d\n",pduwa[n]);
		for (int i=1; i<n; i++) {
			printf("%d ",ptiga[i]);
		}
		printf("%d\n",ptiga[n]);
	}
	
}
