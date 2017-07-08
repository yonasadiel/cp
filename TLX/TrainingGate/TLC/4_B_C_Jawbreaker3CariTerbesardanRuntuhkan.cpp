#include<bits/stdc++.h>
using namespace std;

int pet[30][30];
char baru[30][30];
int jarakmaks=-1,besarkanan,besarbawah;

struct struk {
	int bwh,knn;
	struk(int a, int b) {
		bwh=a;
		knn=b;
	}
};

queue<struk> kue;

int xx[4]={0,1,0,-1};
int yy[4]={1,0,-1,0};

int main() {
	int bawah, kanan, mulaibawah,mulaikanan;
	scanf("%d%d",&bawah,&kanan);
	for (int i=0; i<bawah; i++) {
		for (int j=0; j<kanan; j++) {
			scanf("%d",&pet[i][j]);
			baru[i][j]='0'+pet[i][j];
		}
	}
	
	for (int i=0; i<bawah; i++) {
		for (int j=0; j<kanan; j++) {
			if (pet[i][j]!=0) {
				mulaibawah=i;
				mulaikanan=j;
				
				int dicari=pet[mulaibawah][mulaikanan];
				int jarak=1;
				
				kue.push(struk(mulaibawah,mulaikanan));
				pet[mulaibawah][mulaikanan]=0;
				
				while (!kue.empty()) {
					struk kuren=kue.front();
					kue.pop();
					for (int i=0; i<4; i++) {
						int xn=kuren.bwh+xx[i];
						int yn=kuren.knn+yy[i];
						if (pet[xn][yn]==dicari) {
							kue.push(struk(xn,yn));
							pet[xn][yn]=0;
							jarak++;
						}
					}
				}		
				if (jarak>jarakmaks) {
					jarakmaks=jarak;
					besarbawah=mulaibawah;
					besarkanan=mulaikanan;
				}
			}
		}
	}
	char dicaric=baru[besarbawah][besarkanan];	
	kue.push(struk(besarbawah,besarkanan));
	pet[besarbawah][besarkanan]='.';
	
	while (!kue.empty()) {
		struk kuren=kue.front();
		kue.pop();
		for (int i=0; i<4; i++) {
			int xn=kuren.bwh+xx[i];
			int yn=kuren.knn+yy[i];
			if (baru[xn][yn]==dicaric) {
				kue.push(struk(xn,yn));
				baru[xn][yn]='.';
			}
		}
	}

	for (int i=0; i<bawah; i++) {
		for (int j=0; j<kanan; j++) {
			if (baru[i][j]=='.') {
				for (int k=i; k>0; k--) {
					swap(baru[k][j],baru[k-1][j]);
				}								
			}
		}
	}

	for (int i=0; i<bawah; i++) {
		for (int j=0; j<kanan; j++) {
			printf("%c",baru[i][j]);
			if (j!=kanan-1) {
				printf(" ");
			}
		}
		printf("\n");
	}
}
