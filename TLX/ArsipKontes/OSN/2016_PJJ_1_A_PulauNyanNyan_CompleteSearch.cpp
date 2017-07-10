/* PJJ OSN 2016 1A Pulau NyanNyan
 * SOLUSI COMPLETE SEARCH
 * Tentuin 4, sisanya bisa dicari, trus dicek bener apa engga
 */

#include<bits/stdc++.h>
using namespace std;

string subsoal;
char ch[4][4];
int a,b,c,d,e,f,g,h,i;

int ubah(char cc) {
	if (cc=='s') return 0;
	if (cc=='p') return 3;
	if (cc=='g') return 2;
	if (cc=='d') return 1;
}

int temp[10];
int tekan[10];
int minimumtekan;
int kasus;

int main() {
	cin>>subsoal;
	scanf("%d",&kasus);
	while(kasus--) {
		minimumtekan=1e9;
		for (int j=1; j<=3; j++) {
			for (int k=0; k<=3; k++) {
				scanf("%c",&ch[j][k]);
			}
		}
		
		a=ubah(ch[1][1]); b=ubah(ch[1][2]); c=ubah(ch[1][3]);
		d=ubah(ch[2][1]); e=ubah(ch[2][2]); f=ubah(ch[2][3]);
		g=ubah(ch[3][1]); h=ubah(ch[3][2]); i=ubah(ch[3][3]);
		
		for (int j=0; j<=3; j++) {
			for (int k=0; k<=3; k++) {
				for (int l=0; l<=3; l++) {
					for (int m=0; m<=3; m++) {
						if ((j+k+l+m)%4==b) {
							//cout<<j<<k<<l<<m<<endl;
							temp[1]=j; temp[2]=k; temp[3]=l; temp[5]=m;
							temp[4]=(4+a-(temp[1]+temp[2])%4)%4;
							temp[6]=(4+c-(temp[2]+temp[3])%4)%4;
							temp[7]=(4+d-(temp[1]+temp[4]+temp[5])%4)%4;
							temp[9]=(4+e-(temp[1]+temp[3]+temp[5]+temp[7])%4)%4;
							temp[8]=(4+g-(temp[4]+temp[7])%4)%4;
							
							//for (int n=1; n<=9; n++) cout<<temp[n]; cout<<endl;
							if ((temp[3]+temp[5]+temp[6]+temp[9])%4==f) {
								if ((temp[5]+temp[7]+temp[8]+temp[9])%4==h) {
									if ((temp[6]+temp[8]+temp[9])%4==i) {
										int jumlahtekan=0;
										for (int n=1; n<=9; n++) {
											jumlahtekan+=temp[n];
										}
										if (jumlahtekan < minimumtekan) {
											for (int n=1; n<=9; n++) {
												tekan[n]=temp[n];
												minimumtekan=jumlahtekan;
											}
										}
									}
								}
							}
							
						}
					}
				}
			}
		}
		//printf("%d\n",minimumtekan);
		for (int j=1; j<=9; j++) {
			for (int k=0; k<tekan[j]; k++) {
				printf("%d",j);
			}
		}
		printf("\n");
	}
	
}
