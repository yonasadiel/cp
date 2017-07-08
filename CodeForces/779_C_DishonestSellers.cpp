#include<bits/stdc++.h>
using namespace std;

int n,k;
int ar[200005],br[200005];
pair<int,int> cr[200005];
int ret = 0;

int main() {
	scanf("%d%d",&n,&k);
	for (int i=0; i<n; i++) {
		scanf("%d",&ar[i]);
	}
	for (int i=0; i<n; i++) {
		scanf("%d",&br[i]);
		cr[i].first = ar[i] - br[i];
		cr[i].second = i;
	}
	sort(cr,cr+n);
	for (int i=0; i<n; i++) {
		if (k == 0) {
			ret += min(ar[cr[i].second],br[cr[i].second]);
		} else {
			ret += ar[cr[i].second];
			k--;
		}
	}
	printf("%d\n",ret);
}