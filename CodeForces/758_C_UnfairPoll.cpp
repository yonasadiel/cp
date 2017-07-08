#include<bits/stdc++.h>
using namespace std;

long long cnt[105][105];
long long k;

int main() {
	int n,m,x,y;
	scanf("%d%d%I64d%d%d",&n,&m,&k,&x,&y);
	
	if (n < 3) {
		int nm = n*m;
		long long add = (long long) k / nm;
		k %= nm;
		
		for (int i=0; i<n; i++)
		for (int j=0; j<m; j++)
			cnt[i][j] = add;
		
		for (int i=0; i<n; i++)
		for (int j=0; j<m; j++)
			if (k>0) {
				cnt[i][j]++;
				k--;
			}
		
	} else {
		int nm = 2*n*m - 2*m;
		long long add = (long long) k / nm;
		
		k %= nm;
		for (int i=0; i<n; i++)
		for (int j=0; j<m; j++)
			cnt[i][j] = add;
			
		for (int i=1; i<n-1; i++)
		for (int j=0; j<m; j++)
			cnt[i][j] = 2*add;
			
		for (int i=0; i<n; i++)
		for (int j=0; j<m; j++)
			if (k>0) {
				cnt[i][j]++;
				k--;
			}
			
		for (int i=n-2; i>=0; i--)
		for (int j=0; j<m; j++)
			if (k>0) {
				cnt[i][j]++;
				k--;
			}
	}
			
	long long ma = 0, mi = cnt[0][0];
	for (int i=0; i<n; i++) {
	for (int j=0; j<m; j++) {
		//cout<<cnt[i][j]<<" ";
		ma = max(ma, cnt[i][j]);
		mi = min(mi, cnt[i][j]);
	} //cout<<endl;
	}
	
	
	printf("%I64d %I64d %I64d\n",ma,mi,cnt[x-1][y-1]);
	
}
