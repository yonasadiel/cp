#include <cstdio>
#include <algorithm>
#include <vector>
#define MAXM 10000
#define MAXN 1000000000
#define ll long long
using namespace std;

ll two[MAXM+5];
int twon;
vector<ll> ans;

void precompute() {
	two[0] = 1;
	twon=1;
	for (int i=1; i<MAXM && two[i-1] < MAXN; i++) {
		two[i] = two[i-1] *2;
		twon++;
	}
	for (int i=0; i<twon; i++) {
		two[i] = two[i] - 1;
	}
}

int main() {
	precompute();
	ll x, d;
	scanf("%I64d%I64d", &x, &d);
	ll last = 1;
	while (x > 0) {
		int idx = upper_bound(two, two + twon, x) - two; idx--;
		x -= two[idx];
		for (int i=0; i<idx; i++) {
			ans.push_back(last);
		}
		last += d;
	}
	int ansn = ans.size();
	if (ansn > 10000) {
		printf("-1\n"); return 0;
	}
	printf("%d\n", ansn);
	for (int i=0; i<ansn; i++) {
		printf("%I64d", ans[i]);
		if (i == ansn-1) printf("\n");
		else printf(" ");
	}
}