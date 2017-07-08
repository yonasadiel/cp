#define fi first
#define se second
#include<bits/stdc++.h>
using namespace std;

int r,c;
char peta[1005][1005];
int jarak[1005][1005];
int star,stac;
int mikr,mikc;
queue<pair<int,int> > antri;
int dr[4]={0,1,0,-1};
int dc[4]={1,0,-1,0};

bool valid(int a, int b) {
	if (a>0 && b>0 && a<=r && b<=c) {
		return true;
	} else {
		return false;
	}
}

int main() {
	memset(jarak,-1,sizeof jarak);
	scanf("%d%d",&r,&c); 
	for (int i=1; i<=r; i++) {
		for (int j=0; j<=c; j++) {
			scanf("%c",&peta[i][j]);
			if (peta[i][j]=='E') {
				star=i;
				stac=j;
				peta[i][j]='0';
			}
			if (peta[i][j]=='S') {
				mikr=i;
				mikc=j;
			}
		}
	}
	
	int hitung=0;
	jarak[star][stac]=0;
	antri.push(make_pair(star,stac));
	bool selesai=false;
	int butuh=-1;
	while(!antri.empty()) {
		pair<int,int> kur=antri.front();
		antri.pop();
		if (jarak[kur.fi][kur.se]==butuh) break;
		if (peta[kur.fi][kur.se]!='S')
		hitung+=peta[kur.fi][kur.se]-'0';
//		cout<<kur.fi<<" "<<kur.se<<" "<<jarak[kur.fi][kur.se]<<" "<<hitung<<endl;
		for (int i=0; i<4; i++) {
			int rn=kur.fi+dr[i];
			int cn=kur.se+dc[i];
			if (valid(rn,cn) && jarak[rn][cn]==-1 && peta[rn][cn]!='T') {
				antri.push(make_pair(rn,cn));
				jarak[rn][cn]=jarak[kur.fi][kur.se]+1;
			}
			if (peta[rn][cn]=='S') {
				selesai=true;
				butuh=jarak[rn][cn]+1;
			}
		}
	}
	printf("%d\n",hitung);
}
