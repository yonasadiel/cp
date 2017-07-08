#include<bits/stdc++.h>
using namespace std;

int n;
int a[200005];
vector<int> ft[200005];
vector<int> pt[200005];
int anak[200005];
int saud[200005];
bool isLeaf[200005];
long long sum[200005];
bool visited[200005];
long long dp[200005][3];

void convertTree(int pos) {
	visited[pos] = true;
	int last = -1;
	for (int i=0; i<ft[pos].size(); i++) {
		if (!visited[ft[pos][i]]) {
			pt[pos].push_back(ft[pos][i]);
			if (last == -1) {
				last = ft[pos][i];
				isLeaf[pos] = false;
				anak[pos] = ft[pos][i];
				convertTree(ft[pos][i]);
			} else {
				isLeaf[last] = false;
				saud[last] = ft[pos][i];
				convertTree(ft[pos][i]);
				last = ft[pos][i];
			}
		}
	}
	
}

long long calculate(int pos) {
	if (sum[pos] != -1) return sum[pos];
	if (isLeaf[pos]) return (long long) a[pos];
	long long ret = a[pos];
	for (int i=0; i<pt[pos].size(); i++) {
		ret+= calculate(pt[pos][i]);
	}
	return ret;
}

long long play(int pos, int taken) {
//	cout<<pos<<" "<<taken<<endl;
	long long &ret = dp[pos][taken];
	if (pos == -1) return -1e11;
	
	if (ret != -1) {
		return ret;
	} else {	
		if (isLeaf[pos]) {
//			cout<<"gotcha"<<endl;
			if (taken == 0) {
				ret = -1e11;
			} else if (taken == 1) {
//				cout<<pos;
				ret = sum[pos];
			} else {
				ret = 0;
			}
		} else {
			if (taken == 0) {
				long long case1 = play(anak[pos],0);
				long long case2 = play(saud[pos],0);
				long long case3 = play(anak[pos],1) + play(saud[pos],1);
				long long case4 = sum[pos] + play(saud[pos],1);
				
				if (saud[pos] == -1) ret = case1;
				else if (anak[pos] == -1) ret = max(case2,case4);
				else ret = max(case1,max(case2,max(case3,case4)));
			} else if (taken == 1) {
				long long case1 = play(anak[pos],1);
				long long case2 = play(saud[pos],1);
				long long case4 = sum[pos];
				
				if (saud[pos] == -1) ret = max(case1,case4);
				else if (anak[pos] == -1) ret = max(case2,case4);
				else ret = max(case1,max(case2,case4));
			} else {
				ret = 0;
			}
		}
	}	
	return ret;
}

void bt(int pos, int taken) {
	long long ret = dp[pos][taken];
	
	if (isLeaf[pos]) {
		cout<<pos<<" ";
	} else {
		if (taken == 0) {
			if (saud[pos] == -1) {
				bt(anak[pos],0);
			} else if (anak[pos] == -1) {
				if (ret == play(saud[pos],0)) {
					bt(saud[pos],0);
				} else {
//					cout<<pos<<" ";
					bt(saud[pos],1);
				}
			} else {
				if (ret == play(anak[pos],0)) {
					bt(anak[pos],0);
				} else if (ret == play(anak[pos],0)) {
					bt(anak[pos],0);
				} else if (ret == play(anak[pos],1) + play(saud[pos],1)) {
					bt(anak[pos],1); bt(saud[pos],1);
				} else {
					cout<<pos<<" "; bt(saud[pos],1);
				}
			}
		} else if (taken == 1) {
			if (saud[pos] == -1) {
				if (ret == play(anak[pos],1)) {
					bt(anak[pos],1);
				} else {
					cout<<pos<<" ";
				}
			} else if (anak[pos] == -1) {
				if (ret == sum[pos]) {
					cout<<pos<<" ";
				} else {
					bt(saud[pos],1);
				}
			} else {
				if (ret == play(anak[pos],1)) {
					bt(anak[pos],1);
				} else if (ret == play(saud[pos],1)) {
					bt(saud[pos],1);
				} else {
					cout<<pos<<" ";
				}
			}
		}
	}

}

int main() {
	scanf("%d",&n);
	for (int i=0; i<n; i++) {
		scanf("%d",&a[i]);
	}
	int ia,ib;
	for (int i=0; i<n-1; i++) {
		scanf("%d%d",&ia,&ib);
		ia--;
		ib--;
		ft[ia].push_back(ib);
		ft[ib].push_back(ia);
	}
	
	memset(isLeaf, true, sizeof isLeaf);
	memset(sum, -1, sizeof sum);
	memset(anak,-1, sizeof anak);
	memset(saud,-1, sizeof saud);
	memset(visited, false, sizeof visited);
	convertTree(0);
//	for (int i=0; i<n; i++) printf("%d %d %d\n",i,anak[i],saud[i]);
	for (int i=0; i<n; i++) sum[i] = calculate(i);
//	for (int i=0; i<n; i++) printf("%d %d\n",i,sum[i]);
	
	memset(dp,-1,sizeof dp);
	
	if (play(0,0) < -1e10) {
		printf("Impossible\n");
	} else {
		printf("%I64d\n",play(0,0));
	}
	
//	bt(0,0);
	
	
	
	
}
