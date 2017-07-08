#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;

int n,q;
pair<int,int> arr[300005];
int cnt[300005];

bool komp(pair<int,int> a, pair<int,int>b) {
	if (a.fi == b.fi) {
		return (a.se < b.se);
	} else {
		return (a.fi > b.fi);
	}
}

int main() {
	scanf("%d%d",&n,&q);
	for (int i=0; i<n; i++) {
		scanf("%d%d",&arr[i].fi,&arr[i].se);
	}
	sort(arr,arr+n,komp);
	for (int i=0; i<q; i++) {
		int a;
		scanf("%d",&a); a--;
		pair<int,int> as = arr[a];
		int get = (upper_bound(arr,arr+n,as,komp) - arr) - (lower_bound(arr,arr+n,as,komp) - arr);
		printf("%d\n",get);
	}
}
