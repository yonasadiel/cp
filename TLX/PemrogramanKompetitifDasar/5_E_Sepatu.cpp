#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int n,m;
int bebek[10005];
int sepat[10005];
int a;
int tr;

int main() {
	memset(bebek, 0, sizeof bebek);
	memset(sepat, 0, sizeof sepat);
	scanf("%d%d",&n,&m);
	for (int i=0; i<n; i++) { scanf("%d",&a); bebek[a]++; }
	for (int i=0; i<m; i++) { scanf("%d",&a); sepat[a]++; }
	int cnt=0;
	for (int i=10005; i>=0; i--) {
		tr = min(bebek[i], sepat[i]);
		cnt += tr; bebek[i] -= tr, sepat[i] -= tr;

		tr = min(bebek[i-1], sepat[i]);
		cnt += tr; bebek[i-1] -= tr, sepat[i] -= tr;
	}
	printf("%d\n",cnt);
}