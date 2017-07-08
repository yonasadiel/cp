#include<bits/stdc++.h>
using namespace std;

int n,m,kandidata,kandidatb,harga[10005];
bool oke=false;

void cari() {
	
}

int main() {
	while (scanf("%d",&n)!=EOF) {
//		if (oke) printf("\n");
		oke=true;
		for (int i=0; i<n; i++) {
			scanf("%d",&harga[i]);
		}
		scanf("%d",&m);
		scanf("\n");
		
		sort(harga,harga+n);
		kandidata=0;
		kandidatb=1000009;
		for (int i=0; i<n; i++) {
			for (int j=i+1; j<n; j++) {
				if (harga[i]+harga[j]==m) {
					if ((abs(kandidata-kandidatb))>(abs(harga[i]-harga[j]))) {
						if (harga[i]<harga[j]) {
							kandidata=harga[i];
							kandidatb=harga[j];
						} else {
							kandidata=harga[j];
							kandidatb=harga[i];
						}
					}
				}
			}
		}
		printf("Peter should buy books whose prices are %d and %d.\n\n",kandidata,kandidatb);
	}
}

