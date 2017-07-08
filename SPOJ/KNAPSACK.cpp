#define fi first
#define se second
#include<bits/stdc++.h>
using namespace std;

pair<int,int> arr[2005];
int dp[2005][2005];

int n,s;

int playdp(int pos, int w) {
	cout<<pos<<" "<<w<<endl;
	int &ret = dp[pos][w];
	if (ret != -1) return ret;
	
	if (pos == s) {
		return 0;
	} else {
		ret = playdp(pos+1, w);
		if (w+arr[pos].fi <= n) ret = max(ret, arr[pos].se + playdp(pos+1,w + arr[pos].fi));
		return ret;
	}
}

int main() {
	memset(dp,-1,sizeof dp);
	scanf("%d%d",&n,&s);
	for (int i=0; i<s; i++) {
		scanf("%d%d",&arr[i].fi,&arr[i].se);
	}
	
	printf("%d\n",playdp(0,0));
}
