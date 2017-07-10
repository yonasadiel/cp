#include <cstdio>
#include <algorithm>
#include <vector>
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;

int n;
pii arr[100005];

bool cmp(pii a, pii b) {
	return a.fi+a.se <= b.fi+b.se;
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i=0; i<n; i++) {
		pii a;
		scanf("%d%d",&arr[i].fi,&arr[i].se);
	}
	sort(arr,arr+n,cmp);
	int last = 0, cnt = 0;
	for (int i=0; i<n; i++) {
		if (arr[i].fi >= last) {
			cnt++;
			last = arr[i].fi + arr[i].se;
		}
	}
	printf("%d\n",cnt);
}