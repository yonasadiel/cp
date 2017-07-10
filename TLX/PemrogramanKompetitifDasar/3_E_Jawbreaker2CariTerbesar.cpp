#include<bits/stdc++.h>
#define fi first
#define se second
#define mp(a,b) make_pair(a,b)
using namespace std;

int r,c;
int pet[30][30];

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
	int dr[4] = {0,1,0,-1};
	int dc[4] = {1,0,-1,0};
	
	int ret = 0;
	
	int wa = pet[rx][cx];
	
	queue<pair<int,int> > antri;
	antri.push(mp(rx,cx));
	pet[rx][cx] = -1;
	ret++;
	
	while(!antri.empty()) {
		int rc = antri.front().fi;
		int cc = antri.front().se;
//		cout<<rc<<cc<<endl;
		antri.pop();
		
		for (int i=0; i<4; i++) {
			int rn = rc+dr[i];
			int cn = cc+dc[i];
			if (valid(rn,cn) && pet[rn][cn] == wa) {
				antri.push(mp(rn,cn));
				pet[rn][cn] = -1;
				ret++;
			}
		}
		
	}
	
	return ret;
}

int cariterbesar() {
	int ret = 0;
	for (int i=0; i<r; i++) {
		for (int j=0; j<c; j++) {
			if (pet[i][j] != -1) {
				int t = klik(i,j);
				ret = max(ret,t*(t-1));	
			}
		}
	}
	return ret;
}

int main() {
	input();
	printf("%d\n",cariterbesar());
}
