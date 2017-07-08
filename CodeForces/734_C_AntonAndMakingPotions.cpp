#include<bits/stdc++.h>
using namespace std;

int n,m,k;
long long x,s;
long long ret;
long long arr[200005],brr[200005],crr[200005],drr[200005];

int main() {
	scanf("%d%d%d",&n,&m,&k);
	scanf("%d%d",&x,&s);
	for (int i=1; i<=m; i++) scanf("%d",&arr[i]);
	for (int i=1; i<=m; i++) scanf("%d",&brr[i]);
	for (int i=1; i<=k; i++) scanf("%d",&crr[i]);
	for (int i=1; i<=k; i++) scanf("%d",&drr[i]);
	arr[0] = x; brr[0] = 0; crr[0] = 0; drr[0] = 0;
	
	ret = x*n;
	for (int i=0; i<=m; i++) {
		if (brr[i] <= s) {
			long long sem;
			int indeks = upper_bound(drr,drr+1+k,s-brr[i]) - drr;
			indeks--;
			if (indeks >= 0) {
				sem = (n-crr[indeks])*arr[i];
			} else {
				sem = arr[i]*n;
			}
			ret = min(ret,sem);
			if (ret < 0) cout<<i<<endl;
		}
	}
	printf("%I64d\n",ret);
}

