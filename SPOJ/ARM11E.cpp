#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#define MAXN 100005
using namespace std;

int t,n;

bool pr[MAXN];
vector<int> prth;
int ans [1005];

bool dst(int a) {
	int cnt = 0,j=1;
	while (a!=1) {
		if (cnt >=3) return true;
		if (a % prth[j] == 0) {
			while (a % prth[j] == 0) a /= prth[j];
			cnt++;
		} else {
			j++;
		}
	}
	if (cnt >= 3) return true;
	return false;
}

void generate() {
	prth.push_back(0);
	memset(pr, true, sizeof pr);
	for (int i=2; i<MAXN; i++) {
		if (pr[i]) {
			prth.push_back(i);
			for (int j=2*i; j<MAXN; j+=i) {
				pr[j] = false;
			}
		}
	}
	int prth_size = prth.size()-1;

	for (int i=29, cnt=1; cnt < 1005; i++) {
		if (dst(i)) ans[cnt++] = i;
	}
}

int main() {
	generate();
	scanf("%d",&t);
	while (t--) {
		scanf("%d",&n);
		printf("%d\n",ans[n]);
	}
}