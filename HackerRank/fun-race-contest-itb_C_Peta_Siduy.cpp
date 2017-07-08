#include<bits/stdc++.h>
#define fi first
#define se second
#define mp(a,b) make_pair(a,b)
using namespace std;

int r,c;
char pet[3005][3005];
int dist[3005][3005];
pair<int,int> s,f;
queue<pair<int,int> > q;
int dr[4] = {0,1,0,-1};
int dc[4] = {1,0,-1,0};

bool valid(pair<int,int>a) {
	return a.fi > 0 && a.fi <= r && a.se > 0 && a.se <= c;
}

int main() {
	memset(dist,-1,sizeof dist);
	scanf("%d%d",&r,&c);
	for (int i=1; i<=r; i++) {
		for (int j=0; j<=c; j++) {
			scanf("%c",&pet[i][j]);
			if (pet[i][j] == 'S') s=mp(i,j);
			if (pet[i][j] == 'F') f=mp(i,j);
		}
	}
	
	dist[s.fi][s.se] = 0;
	q.push(s);
	while (!q.empty()) {
		pair<int,int> c = q.front();
		q.pop();
		for (int i=0; i<4; i++) {
			pair<int,int> n = mp(c.fi+dr[i],c.se+dc[i]);
			if (valid(n) && pet[n.fi][n.se] != '*' && dist[n.fi][n.se] == -1) {
				dist[n.fi][n.se] = dist[c.fi][c.se] + 1;
				q.push(n);
			}
		}
	}
	printf("%d\n",dist[f.fi][f.se]);
	
}
