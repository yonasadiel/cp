#include<bits/stdc++.h>
#define INF 100000000000000000
using namespace std;

int koorx[305];
int koory[305];

int main()  {
	int n;
	scanf("%d",&n);
	for (int i=0; i<n; i++) {
		scanf("%d%d",&koorx[i],&koory[i]);
	}
	int angka[3];
	long long luasmin = INF;
	bool cek=false;
	int a=0,b=0,c=0;
	for (int x=0; x<n; x++) {
		for (int y=0; y<n; y++) {
			for (int z=0; z<n; z++) {
				if (x!=y && y!=z && x!=z) {
//					cout<<koorx[x]<<","<<koory[x]<<" "<<koorx[y]<<","<<koory[y]<<" "<<koorx[z]<<","<<koory[z]<<" ";
					long long luas=abs((koorx[x]*koory[y])+(koorx[y]*koory[z])+(koorx[z]*koory[x])-(koory[x]*koorx[y])-(koory[y]*koorx[z])-(koory[z]*koorx[x]));
//					printf("%lld",luas);
					if (luas==luasmin) {
						angka[0]=x;
						angka[1]=y;
						angka[2]=z;
						sort(angka,angka+3);
						if (a!=angka[0] && b!=angka[1] && c!=angka[3]) {
							cek=true;
//							printf("sama");
						}
					}
					if (luas!=0) {
						if (luas<luasmin) {
							angka[0]=x;
						angka[1]=y;
						angka[2]=z;
						sort(angka,angka+3);
//							printf("baru");
							a=angka[0];
							b=angka[1];
							c=angka[2];
							cek=false;
							luasmin=luas;
						}
					}
//				printf("\n");
				}
			}
		}
	}
	//printf("%.2lf %d\n", luasmin , (luasmin==9999999999999.00));
	if (luasmin==INF || cek) {
		printf("-1.00\n");
		return 0;
	}
	printf("%.2lf\n",double(luasmin/2.00));
}
