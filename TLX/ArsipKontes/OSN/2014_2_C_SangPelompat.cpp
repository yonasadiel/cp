#include<bits/stdc++.h>
using namespace std;
//BFS biasa
//cari aja ya soalnya, males njelasin. OSN 2014

int r,c;
char petak[1005][1005];
int lompat_minimal[1005][1005];
int rn,cn,ro,co;
queue <pair<int,int> > antrian;
int rd[4]={0,1,0,-1};
int cd[4]={1,0,-1,0};

int main() {
	memset(lompat_minimal,-1,sizeof lompat_minimal);
	string dummy;
	cin>>dummy;
	scanf("%d%d",&r,&c);
	for (int i=1; i<=r; i++) {
		for (int j=0; j<=c; j++) {
			scanf("%c",&petak[i][j]);
			if (petak[i][j]=='S') {
				ro=i;
				co=j;
			}
			if (petak[i][j]=='T') {
				rn=i;
				cn=j;
				petak[i][j]='#';
			}
		}
	}
	
	antrian.push(make_pair(ro,co));
	lompat_minimal[ro][co]=0;
	
	while(!antrian.empty()) {
		int rs=antrian.front().first;
		int cs=antrian.front().second;
//		cout<<rs<<" "<<cs<<" "<<lompat_minimal[rs][cs]<<endl;
		antrian.pop();
		for (int i=0; i<4; i++) {
			for (int j=1; j<=1005; j++) {
				int rb=rs+rd[i]*j;
				int cb=cs+cd[i]*j;
				if (rb>0 && cb>0 && rb<=r && cb<=c) {
					if (petak[rb][cb]=='#') {
						int temp=lompat_minimal[rs][cs];
						if (j>1) {
							temp++;
						}
						if (lompat_minimal[rb][cb]==-1 || temp<lompat_minimal[rb][cb]) {
							antrian.push(make_pair(rb,cb));
							lompat_minimal[rb][cb]=temp;
						} 
						break;
					}
				} else {
					break;
				}
			}
		}
	}
	for (int i=1; i<=r; i++) {
		for (int j=0; j<=c; j++) {
//			printf("%d ",lompat_minimal[i][j]);
		}
//		cout<<endl;
	}
	cout<<lompat_minimal[rn][cn]<<endl;
}
