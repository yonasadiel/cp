#include <cstdio>
#include <iostream>
#include <map>
using namespace std;

int n,k,m,x;
int a[100005];
int b[100005];
string word;
map<string, int> p;

int main() {
	scanf("%d%d%d",&n,&k,&m);
	for (int i=0; i<n; i++) {
		cin >> word;
		p[word] = i;
	}
	for (int i=0; i<n; i++) {
		scanf("%d",&a[i]);
	}
	for (int i=0; i<k; i++) {
		scanf("%d", &x);
		int c = 0;
		for (int j=0; j<x; j++) {
			scanf("%d", &b[j]);
			if (a[b[j]-1] < a[b[c]-1]) { c = j; }
		}
		for (int j=0; j<x; j++) {
			a[b[j]-1] = a[b[c]-1];
		}
	}
	long long ans = 0;
	for (int i=0; i<m; i++) {
		cin >> word;
		ans += (long long) a[p[word]];
	}
	printf("%I64d\n", ans);
}