#include <bits/stdc++.h>
using namespace std;

int level, baris, kolom;
int dl[6]={0,1,0,-1,0,0};
int db[6]={1,0,-1,0,0,0};
int dk[6]={0,0,0,0,1,-1};
char petak[35][35][35];
int menit[35][35][35];
char dump;

struct struk {
	int lev, bar, kol;
	struk () {	};
	struk (int m, int n, int o) {
		lev=m;
		bar=n;
		kol=o;
	}
};
struk selesai,kuren;

queue <struk> antri;

bool masuk_area(int a, int b, int c) {
	return (a>=0 && a<level && b>=0 && c>=0 && b<baris && c<kolom && petak[a][b][c]!='#');
}

int main() {
	while (true) {
		memset(menit,-1,sizeof menit);
		scanf("%d%d%d",&level,&baris,&kolom);
		if (level==0 && baris==0 && kolom==0) {
			break;
		}
		scanf("%c",&dump);
		for (int i=0; i<level; i++) {
			for (int j=0; j<baris; j++) {
				for (int k=0; k<kolom; k++) {
					scanf("%c",&petak[i][j][k]);
					if (petak[i][j][k]=='S') {
						antri.push(struk(i,j,k));
						menit[i][j][k]=0;
					}
					if (petak[i][j][k]=='E') {
						selesai=struk(i,j,k);
					}
				}
				scanf("%c",&dump);
			}
			scanf("%c",&dump);
		}
		while (!antri.empty()) {
			kuren=antri.front();
			antri.pop();
			for (int i=0; i<6; i++) {
				int ln=kuren.lev+dl[i];
				int bn=kuren.bar+db[i];
				int kn=kuren.kol+dk[i];
				if (masuk_area(ln,bn,kn) && menit[ln][bn][kn]==-1) {
					menit[ln][bn][kn]=menit[kuren.lev][kuren.bar][kuren.kol]+1;
//					cout<<ln<<" "<<bn<<" "<<kn<<" "<<menit[ln][bn][kn]<<endl;
					antri.push(struk(ln,bn,kn));
				}
			}
		}
		if (menit[selesai.lev][selesai.bar][selesai.kol]!=-1) {
			printf("Escaped in %d minute(s).\n",menit[selesai.lev][selesai.bar][selesai.kol]);
		} else {
			printf("Trapped!\n");
		}
		
		
	}
}
