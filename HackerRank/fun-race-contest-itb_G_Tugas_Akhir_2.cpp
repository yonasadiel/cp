#include<bits/stdc++.h>
using namespace std;

int n,q,m;
vector<int> edge[1005];
int dp[1005][1005];
int c[1005];

int play(int pos, int color, int parent) {
	int &ret = dp[pos][color];
	if (ret != -1) return ret;
	ret = 0;
	if (c[pos] == color) ret++;
	if (edge[pos].size() == 1 && edge[pos][0] == parent) {
		return ret;
	}
	for (int i=0; i<edge[pos].size(); i++) {
		//cout<<edge[pos][i];
		if (edge[pos][i] != parent) {
			ret += play(edge[pos][i],color,pos);
		}
	}
	//cout<<pos<<" "<<color<<" "<<parent<<"="<<ret<<endl;
	return ret;
	
}

int main() {
	memset(dp,-1,sizeof dp);
	scanf("%d",&n);
	for (int i=0; i<n; i++) {
		scanf("%d",&c[i]);
	}
	for (int i=0; i<n-1; i++) {
		int a,b;
		scanf("%d%d",&a,&b);
		a--; b--;
		edge[a].push_back(b);
		edge[b].push_back(a);
	}
	for (int i=0; i<1005; i++) {
		dp[0][i] = play(0,i,1005);
		//cout<<dp[0][i]<<endl;
	}
	scanf("%d",&q);
	for (int i=0; i<q; i++) {
		int a,b;
		scanf("%d%d",&a,&b);
		a--;
		printf("%d\n",dp[a][b]);
	}
}
