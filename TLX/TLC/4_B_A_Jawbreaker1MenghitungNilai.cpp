#include<bits/stdc++.h>
using namespace std;

int pet[30][30];

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
		}
	}
	scanf("%d%d",&mulaibawah,&mulaikanan);
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
	printf("%d\n", jarak*(jarak-1));
}
