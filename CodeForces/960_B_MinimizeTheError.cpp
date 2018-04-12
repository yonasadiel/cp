#include <cstdio>
#include <algorithm>
#include <queue>
#define ll long long
using namespace std;

ll n, k1, k2;
ll a[1005], b[1005], c[1005];
priority_queue<ll> pq;

int main() {
	scanf("%I64d%I64d%I64d", &n, &k1, &k2);
	for (int i=0; i<n; i++) { scanf("%I64d", &a[i]); if (a[i] > 1000000) return 1; }
	for (int i=0; i<n; i++) { scanf("%I64d", &b[i]); if (b[i] > 1000000) return 1; }
	for (int i=0; i<n; i++) { c[i] = a[i] - b[i]; pq.push(max(c[i], -c[i])); }

	while (k1+k2 > 0) {
		ll t = pq.top(); pq.pop();
		t = max(t-1, 1-t);
		pq.push(t); k1--;
	}

	ll sum = 0;
	while (!pq.empty()) {
		ll t = pq.top(); pq.pop();
		sum += t*t;
	}
	while (sum < 0);
	printf("%I64d\n", sum);
}