#include<bits/stdc++.h>
#define fi first
#define se second
#define mp(a,b) make_pair(a,b)
using namespace std;

int r,c;
int pet[30][30];
int pett[30][30];

void input() {
	scanf("%d%d",&r,&c);
	for (int i=0; i<r; i++) {
		for (int j=0; j<c; j++) {
			scanf("%d",&pet[i][j]);
		}
	}
}

bool valid(int rx, int cx) {
	return (rx>=0 && rx<r && cx>=0 && cx<c);
}

int klik(int rx, int cx) {
	for (int i=0; i<r; i++) {
		for (int j=0; j<c; j++) {
			pett[i][j] = pet[i][j];
		}
	}
	
	int dr[4] = {0,1,0,-1};
	int dc[4] = {1,0,-1,0};
	
	int ret = 0;
	
	int wa = pett[rx][cx];
	
	queue<pair<int,int> > antri;
	antri.push(mp(rx,cx));
	pett[rx][cx] = -1;
	ret++;
	
	while(!antri.empty()) {
		int rc = antri.front().fi;
		int cc = antri.front().se;
//		cout<<rc<<cc<<endl;
		antri.pop();
		
		for (int i=0; i<4; i++) {
			int rn = rc+dr[i];
			int cn = cc+dc[i];
			if (valid(rn,cn) && pett[rn][cn] == wa) {
				antri.push(mp(rn,cn));
				pett[rn][cn] = -1;
				ret++;
			}
		}
		
	}
	
	return ret;
}

pair<int,int> cariterbesar() {
	int ret = 0;
	int rm=0, cm=0;
	for (int i=0; i<r; i++) {
		for (int j=0; j<c; j++) {
			if (pet[i][j] != -1) {
				int t = klik(i,j);
				if (t*(t-1) > ret) {
					ret = t*(t-1);
					rm=i; cm=j;
				}
			}
		}
	}
	return mp(rm,cm);
}

void runtuhkan(pair<int,int> k) {
	klik(k.fi, k.se);
	for (int j=0; j<c; j++) {
		for (int i=r-2; i>=0; i--) {
			if (pett[i][j] != -1 && pett[i+1][j] == -1) {
				int s = i;
				while (pett[s+1][j] == -1) {
					s++;
				}
				swap(pett[i][j],pett[s][j]);
			}
		}
	}
}

void out() {
	for (int i=0; i<r; i++) {
		for (int j=0; j<c; j++) {
			if (pett[i][j] == -1) {
				printf(".");
			} else {
				printf("%d",pett[i][j]);
			}
			if (j==c-1) {
				printf("\n");
			} else {
				printf(" ");
			}
		}
	}
}

int main() {
	input();
	runtuhkan(cariterbesar());
	out();
}
