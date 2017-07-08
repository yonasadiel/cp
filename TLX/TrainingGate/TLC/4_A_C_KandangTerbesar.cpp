#include<bits/stdc++.h>
using namespace std;

char pet[505][505];

int c,r;

bool valid(int x,int y) {
	return (x>0 && y>0 && x<=r && y<=c);
}

int xx[]={0,1,0,-1};
int yy[4]={1,0,-1,0};
int bawalr,bawalc,kawalr,kawalc,luasb,luask;

struct struk {
	int x,y;
	struk(int a,int b) {
		x=a;
		y=b;
	}
};

int main() {
	scanf("%d%d",&c,&r);
	for (int i=1; i<=r; i++) {
		for (int j=0; j<=c; j++) {
			scanf("%c",&pet[i][j]);
			if (pet[i][j]=='B') {
				bawalr=i;
				bawalc=j;
			}
			if (pet[i][j]=='K') {
				kawalr=i;
				kawalc=j;
			}
		}
	}
//	cout << bawalr<<bawalc<<kawalr<<kawalc<<endl;
	int luask=1;luasb=1;
	
	
	queue <struk> antri;
	
	antri.push(struk(bawalr,bawalc));
	pet[bawalr][bawalc]='#';
//	int angka;
	
	while(!antri.empty()) {
		struk kuren=antri.front();
		antri.pop();
		for (int i=0; i<4; i++) {
			int xn=kuren.x + xx[i];
			int yn=kuren.y + yy[i];
			if (pet[xn][yn]=='K') {
				printf("SERI\n");
				return 0;
			}
			if (valid(xn,yn) && pet[xn][yn]=='.') {
//			cout<<xn<<yn<<endl;
//			scanf("%d\n",&angka);
				pet[xn][yn]='#';
				luasb++;
				antri.push(struk(xn,yn));
//		cout<<xn<<yn<<endl;
			}
		}
	}
	
	antri.push(struk(kawalr,kawalc));
	pet[kawalr][kawalc]='#';
	
	while(!antri.empty()) {
		struk kuren=antri.front();
		antri.pop();
		for (int i=0; i<4; i++) {
			int xn=kuren.x + xx[i];
			int yn=kuren.y + yy[i];
			if (valid(xn,yn) && pet[xn][yn]=='.') {
				pet[xn][yn]='#';
				luask++;
				antri.push(struk(xn,yn));
			}
		}
	}
	if (luask<luasb) {
		printf("B %d\n",luasb-luask);
	}
	if (luask>luasb) {
		printf("K %d\n",luask-luasb);
	}
	if (luask==luasb) {
		printf("SERI\n");
	}
	return 0;
}
