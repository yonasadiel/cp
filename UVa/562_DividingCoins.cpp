#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

int n,total;
int arr[105];
int debug;
int dp[105][50000];

int selisih(int pos, int jumlah) {
	if (jumlah>=total/2) {
		return jumlah;
	}
	if (pos>n) {
		return 99999999;
	}
	if (dp[pos][jumlah]!=-1) {
		return dp[pos][jumlah];
	}
	dp[pos][jumlah]= min( selisih (pos+1,jumlah+arr[pos]),selisih (pos+1,jumlah));
	return dp[pos][jumlah];
}

int main() {
	int kase;
	scanf("%d",&kase);
	while (kase--) {
		memset(dp,-1,sizeof dp);
		scanf("%d",&n);
		total=0;
		for (int i=1; i<=n; i++) {
			scanf("%d",&arr[i]);
			total+=arr[i];
		}
		if (n==1) {
			printf("%d\n",arr[1]);
			continue;
		}
		if (total%2==0) {
			printf("%d\n",2*(selisih(1,0)-total/2));
		} else {
			printf("%d\n",abs(2*(selisih(1,0)-total/2)-1));
		}
	}
}
