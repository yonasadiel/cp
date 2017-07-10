#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n;
int arr[105];
int brr[105];
int dp[105][105];

int ngedp(int a, int b) {
	if (dp[a][b] != -1) {
		return dp[a][b];
	}
	int &ret = dp[a][b];

	if (a >= n || b >= n) {
		ret = 0;
	} else {
		if (arr[a] == brr[b]) {
			ret = 1 + ngedp(a+1,b+1);
		} else {
			ret = max(ngedp(a+1,b), ngedp(a,b+1));
		}
	}

	return ret;
}

void bt(int a, int b) {
	if (a >= n || b >= n) {
		return;
	} else {
		if (arr[a] == brr[b]) {
			printf("ambil\n");
			bt(a+1,b+1);
		} else {
			if (ngedp(a,b) == ngedp(a+1,b)) {
				printf("atas\n");
				bt(a+1,b);
			} else {
				printf("bawah\n");
				bt(a,b+1);
			}
		}
	}
	return;
}

int main() {
	scanf("%d",&n);
	for (int i=0; i<n; i++) { scanf("%d",&arr[i]); }
	for (int i=0; i<n; i++) { scanf("%d",&brr[i]); }

	memset(dp,-1,sizeof dp);
	printf("%d\n",ngedp(0,0));

	//bt(0,0);
}