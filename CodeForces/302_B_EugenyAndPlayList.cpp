#include<bits/stdc++.h>

int main() {
	
	int n,m;
	int menit[100000];
	int lagu=1, indeks=1;
	int hasil,kali,waktu,tanya;
	menit[0]=0;
	
	scanf("%d %d",&n,&m);
	while (n--) {
		scanf("%d %d",&kali,&waktu);
		hasil=kali*waktu;
		menit[lagu]=menit[lagu-1]+hasil;
//		printf("%d \n",menit[lagu]);
		lagu++;			
	}

	while (m--) {
		scanf("%d",&tanya); 
		int min=1, maks=lagu-1;
		while(min<=maks){
			int tengah=(min+maks)/2;
//			printf("min %d maks %d\n",min, maks);
			if ((tanya <= menit[tengah])&&(tanya > menit[tengah-1])) {
				printf("%d\n",tengah);
//				printf("haha1");
				break;
			}
			if ((tanya > menit[tengah])&&(tanya <= menit[tengah+1])) {
				printf("%d\n",tengah+1);
//				printf("haha2");
				break;
			}
			if ((tanya > menit[tengah])&&(tanya > menit[tengah+1])) {
				min = tengah+1;
//				printf("haha3");
			}
			if ((tanya <= menit[tengah])&&(tanya <= menit[tengah-1])) {
				maks = tengah;
			}
				
		}
		
	}	
	
	return 0;
}
