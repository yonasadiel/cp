#include<bits/stdc++.h>
#define INF 1e9;
using namespace std;

string arr[100];
int minia[100],minib[100],minic[100];
int dp[50][55][55][55];
	int n,m;
	bool debug = false;

int playdp(int pos, int a, int b, int c) {
	int &ret = dp[pos][a][b][c];
	if (ret !=-1) return ret;
	if (pos == n) {
		if (a==54 || b==54 || c==54) return INF;
		return minia[a]+minib[b]+minic[c];
	}
	ret = playdp(pos+1,a,b,c);
	if (a!=pos) ret = min(ret,playdp(pos+1,pos,b,c));
	if (b!=pos) ret = min(ret,playdp(pos+1,a,pos,c));
	if (c!=pos) ret = min(ret,playdp(pos+1,a,b,pos));
	if (debug) cout<<pos<<" "<<a<<" "<<b<<" "<<c<<" "<<ret<<endl;
	return ret;
}

int main() {
	memset(dp,-1,sizeof dp);
	for (int i=0; i<100; i++) {
		minia[i] = 1000;
		minib[i] = 1000;
		minic[i] = 1000;
	}
	scanf("%d%d",&n,&m);
	for (int i=0; i<n; i++) {
		cin>>arr[i];
		for (int j=0; j<m; j++) {
			if (arr[i][j]>='a' && arr[i][j]<='z') minia[i] = min(minia[i],min(j,m-j));
			if (arr[i][j]>='0' && arr[i][j]<='9') minib[i] = min(minib[i],min(j,m-j));
			if (arr[i][j]=='*' || arr[i][j]=='#' || arr[i][j]=='&') minic[i] = min(minic[i],min(j,m-j));
		}
		if (debug) cout<<minia[i]<<" "<<minib[i]<<" "<<minic[i]<<endl;
	}
	int mini = INF;
	for (int i=0; i<n; i++) 
	for (int j=0; j<n; j++)
	for (int k=0; k<n; k++) {
		if (i!=j && i!=k && j!=k) mini = min(mini,minia[i]+minib[j]+minic[k]);
	}
	if (mini<1000) {
		cout<<mini<<endl;
	} else {
		while(1);
	}
	
	//printf("%d\n",playdp(0,54,54,54));
}
