#include<bits/stdc++.h>
using namespace std;

int n,m,k;

bool validd(int x,int y) {
	return (x>0 && y>0 && x<=n && y<=m);
}

char peta[505][505],baru[505][505];
int titik=0;

struct struk {
	int x,y;
	struk(int a,int b) {
		x=a;
		y=b;
	}
};

queue<struk> kue;

int main() {
	scanf("%d %d %d",&n,&m,&k);
	for (int i=1; i<=n; i++) {
		for (int j=1; j<=m; j++) {
			baru[i][j]='X';
		}
	}
	for (int i=1; i<=n; i++) {
		for (int j=0; j<=m; j++) {
			scanf("%c",&peta[i][j]);
			if (peta[i][j]=='.') titik++;
			if (peta[i][j]=='#') baru[i][j]='#';
		}
	}
	
	int xx[4]={1,0,-1,0};
	int yy[4]={0,1,0,-1};
	int bikin=titik-k;
	int mulaii=0,mulaij=0;
	
	while (true) {
		for (int i=1; i<=n; i++) {
			for (int j=1; j<=m; j++) {
				if (baru[i][j]=='X') {
					mulaii=i;
					mulaij=j;
					break;
				}
			}
			if (mulaii!=0) break;
		}
//		cout<<mulaii<<" "<<mulaij<<endl;
		
		baru[mulaii][mulaij]=='.';
		bikin--;
		kue.push(struk(mulaii,mulaij));
		
		while(bikin>=0) {
			struk kuren=kue.front();
			kue.pop();
//	cout<<"haha"<<endl;
			for (int h=0; h<4; h++) {
				if (baru[kuren.x+xx[h]][kuren.y+yy[h]]=='X' && validd(kuren.x+xx[h],kuren.y+yy[h])) {
					baru[kuren.x+xx[h]][kuren.y+yy[h]]='.';
					kue.push(struk(kuren.x+xx[h],kuren.y+yy[h]));
					bikin--;
					if (bikin<0) break;
				}
			}
			if (bikin<0) break;
		}		
		if (bikin<0) break;
				
	}
	for (int i=1; i<=n; i++) {
		for (int j=1; j<=m; j++) {
			printf("%c",baru[i][j]);
		}
		printf("\n");
	}
	
	 
}
