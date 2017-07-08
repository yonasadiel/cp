#define MOD 1000000007
#include<bits/stdc++.h>
using namespace std;

int t;
int n;
bool bisa[10][10];
long long depe[100005][10];

void init() {
	bisa[1][2]=true; bisa[1][4]=true;
	bisa[2][1]=true; bisa[2][3]=true; bisa[2][5]=true;
	bisa[3][2]=true; bisa[3][6]=true;
	bisa[4][1]=true; bisa[4][5]=true; bisa[4][7]=true;
	bisa[5][2]=true; bisa[5][4]=true; bisa[5][6]=true; bisa[5][8]=true;
	bisa[6][3]=true; bisa[6][5]=true; bisa[6][9]=true;
	bisa[7][4]=true; bisa[7][8]=true; bisa[7][0]=true;
	bisa[8][5]=true; bisa[8][7]=true; bisa[8][9]=true;	
	bisa[9][8]=true; bisa[9][6]=true;
	bisa[0][7]=true;
}

long long dfs(int pos, int last) {
	long long &ret=depe[pos][last];
	if (ret!=-1) return ret;
	if (pos==0) {ret=1; return ret;	}
	ret=0;
	for (int i=0; i<10; i++) {
		if (bisa[last][i]) {
			ret=(ret+dfs(pos-1,i)%MOD)%MOD;
		}
	}
	return ret;
}

int main() {
	scanf("%d",&t);
	memset(depe,-1,sizeof depe);
	memset(bisa,false,sizeof bisa);
	init();
	while(t--) {
		scanf("%d",&n);
		long long hasil=0;
		for (int i=0; i<10; i++) {
			hasil=(hasil+dfs(n-1,i)%MOD)%MOD;
		}
		printf("%d\n",hasil);
		
	}
}
