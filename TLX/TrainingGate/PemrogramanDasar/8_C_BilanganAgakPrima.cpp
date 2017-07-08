#include<bits/stdc++.h>
using namespace std;

int main() {
	int n,jumlah;
	scanf("%d",&jumlah);
	while(jumlah--) {
		scanf("%d",&n);
		if (n>1) {
				int cek=2;
			int prima=0;
			while(cek<=sqrt(n)) {
				if (n%cek==0) {
					prima++;
				}
				cek++;
			
			}
		if (prima<=1) printf("YA\n"); else printf("BUKAN\n");
		} else {
		printf("YA\n");
	}
	}
	
}
