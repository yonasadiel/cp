#include<bits/stdc++.h>
using namespace std;

int bawah,kanan,finisbawah,finiskanan,mulaibawah,mulaikanan;

struct struk {
	int bwh,knn;
	struk(int a,int b) {
		bwh=a;
		knn=b;
	}
};
queue <struk>kue;

char peta[505][505];

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

bool valid(int a, int b) {
	return (a>0 && b>0 && a<=bawah && b<=kanan);
}

int main() {
	scanf("%d %d",&bawah,&kanan);
	for (int i=1; i<=bawah; i++) {
		for (int j=0; j<=kanan; j++) {
			scanf("%c",&peta[i][j]);
		}
	}
	scanf("%d%d%d%d",&finisbawah,&finiskanan,&mulaibawah,&mulaikanan);

	kue.push(struk(mulaibawah,mulaikanan));
	bool cek=true;
	if (peta[mulaibawah][mulaikanan]=='X') {
		cek=false;
	}
	peta[mulaibawah][mulaikanan]='X';
	
	
	int hitung=0;
	for (int i=0; i<4; i++) {
		int xn=mulaibawah+dx[i];
		int yn=mulaikanan+dy[i];
		if (valid(xn,yn)) {
			if (peta[xn][yn]=='.') {
				hitung++;
			}			
		}
	} 
	if (abs(finisbawah-mulaibawah)+abs(finiskanan-mulaikanan)==1 && hitung >0) {
		printf("YES\n");
		return 0;
	}
	if (finisbawah==mulaibawah && finiskanan==mulaikanan && hitung>0) {
		printf("YES\n");
		return 0;
	}
	if (finisbawah==mulaibawah && finiskanan==mulaikanan && hitung==0) {
		printf("NO\n");
		return 0;
	}
	if (hitung<2 && cek) {
		printf("NO\n");
		return 0;
	}
	
	while (!kue.empty()) {
//	cout<<"haha"<<endl;
		struk kuren=kue.front();
		kue.pop();
//		cout<<kuren.bwh<<" "<<kuren.knn<<endl;
		for (int i=0; i<4; i++) {
			int xn=kuren.bwh+dx[i];
			int yn=kuren.knn+dy[i];
			if (xn==finisbawah && yn == finiskanan) {
				printf("YES\n");
				return 0;
			}
			if (valid(xn,yn)) {
				if (peta[xn][yn]=='.') {
					peta[xn][yn]='X';
					kue.push(struk(xn,yn));
				}			
			}
		}
	}
	printf("NO\n");
	return 0;
}
