#include<bits/stdc++.h>
using namespace std;

char pet[85][85];
int lebar,panjang;

int n,m,k,kurbar,kurkol;
	int xx[4]={1,0,-1,0};
	int yy[4]={0,1,0,-1};

bool validd(int x,int y) {
	return (x>0 && y>0 && x<=panjang && y<=lebar);
}

struct kuren {
	int baris,kolom;
	kuren(int a, int b) {
		baris=a; kolom=b;
	}
};
queue<kuren> q;

int main() {
	int rumah;
	scanf("%d",&rumah);
	while (rumah--) {
		scanf("%d %d",&panjang,&lebar);	
//		cout<<panjang<<lebar<<endl;
		for (int i=1; i<=panjang; i++) {
			for (int j=0; j<=lebar; j++) {
				scanf("%c",&pet[i][j]);
	//		cout<<j<<endl;
			}
		}
		for (int i=1; i<=lebar; i++) {
			if (pet[1][i]==' ') {
				pet[1][i]='#';
				q.push(kuren(1,i));
			}
		}
		for (int i=1; i<=panjang; i++) {
			if (pet[i][1]==' ') {
				pet[i][1]='#';
				q.push(kuren(i,1));
			}
		}
		for (int i=1; i<=panjang; i++) {
			if (pet[i][lebar]==' ') {
				pet[i][lebar]='#';
				q.push(kuren(i,lebar));
			}			
		}
		for (int i=1; i<=lebar; i++) {
			if (pet[panjang][i]==' ') {
				pet[panjang][i]='#';
				q.push(kuren(panjang,i));
			}			
		}
		
		
//		kuren lagi=q.front();
		while(!q.empty()) {
			kuren lagi=q.front();
			q.pop();
//		printf("%d %d",lagi.baris,lagi.kolom);
			for (int i=0; i<4; i++) {
				int xn=lagi.baris+xx[i];
				int yn=lagi.kolom+yy[i];
				
				if(validd(xn,yn) && pet[xn][yn]==' ') {
					pet[xn][yn]='#';
					q.push(kuren(xn,yn));
				}
			}
		}
/*		for (int i=1; i<=panjang; i++) {
			for (int j=1; j<=lebar; j++) {
				printf("%c",pet[i][j]);
			cout<<j<<endl;
			}
			printf("\n");
		}*/
//		printf("haha");
		bool cek=true;
		for (int i=1; i<=panjang; i++) {
			for (int j=1; j<=lebar; j++) {
				if (pet[i][j]!='#') {
					cek=false;
				}
			}
		}
		if (cek) printf("TIDAK\n");
		else printf("YA\n");
	}
}
