#define fi first
#define se second
#include<bits/stdc++.h>
using namespace std;

int bg,p;
int w[1050];
int v[1050];
pair<int,int> dp[1050][5050];
bool ambil[1050];

pair<int,int> playdp(int now, int fee) {
	pair<int,int> &ret=dp[now][fee];
	if (ret.fi>-1) {
		return ret;
	}
	if (now==p) return ret=make_pair(0,0);
	if (fee>=w[now]) {
		if (playdp(now+1,fee-w[now]).fi+v[now]>playdp(now+1,fee).fi) {
			ret=make_pair(playdp(now+1,fee-w[now]).fi+v[now],playdp(now+1,fee-w[now]).se+w[now]);
		} else if (playdp(now+1,fee-w[now]).fi+v[now]==playdp(now+1,fee).fi) {
			if (playdp(now+1,fee-w[now]).se+w[now]>playdp(now+1,fee).se) {
				ret=playdp(now+1,fee);
			} else {
				ret=make_pair(playdp(now+1,fee-w[now]).fi+v[now],playdp(now+1,fee-w[now]).se+w[now]);
			}
		} else {
			ret=playdp(now+1,fee);
		}
	} else {
		ret=playdp(now+1,fee);
	}
	return ret;
}

void backtrack(int now, int fee) {
	if (now==p) return;
	if (fee>=w[now]) {
		if (dp[now][fee]==dp[now+1][fee]) {
			backtrack(now+1,fee);
		} else {
			ambil[now]=true;
			backtrack(now+1,fee-w[now]);
		}
	} else {
		backtrack(now+1,fee);
	}
}

int main() {
	cin>>bg>>p;
	while(bg!=0 && p!=0) {
		memset(dp,-1,sizeof dp);
		memset(ambil,false,sizeof ambil);
		for (int i=0; i<p; i++) {
			scanf("%d%d",&w[i],&v[i]);
		}
		
		playdp(0,bg);
//		backtrack(0,bg);
/*		int res=0;
		for (int i=0; i<p; i++) {
			if (ambil[i]) res+=w[i];
		}*/
		cout<<dp[0][bg].se<<" "<<dp[0][bg].fi<<endl;
		cin>>bg>>p;
	}
}
