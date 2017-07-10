#include<bits/stdc++.h>
using namespace std;

int main() {
	int jumlah,maks;
	long long total=0;
	int tinggi[3];
	scanf("%d %d",&jumlah,&maks);
	for (int i=1; i<=jumlah/maks;i++) {
		tinggi[0]=0;
		for (int j=1; j<=maks;j++) {
			scanf("%d",&tinggi[1]);
			if (tinggi[1]>tinggi[0]) tinggi[0]=tinggi[1];
		}
		total+=tinggi[0];
		total++;
	}
//	for (int i=1; i<=jumlah%maks; i++) {
	if 	(jumlah%maks!=0) {
		tinggi[0]=0;
		for (int j=1; j<=jumlah%maks;j++) {
			scanf("%d",&tinggi[1]);
			if (tinggi[1]>tinggi[0]) tinggi[0]=tinggi[1];
		}
		total+=tinggi[0];
		total++;
	}
//	}
	printf("%lld\n",total+1);
	return 0;
}


