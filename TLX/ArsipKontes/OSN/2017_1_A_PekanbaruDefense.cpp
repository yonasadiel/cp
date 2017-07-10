/**
 * PekanbaruDefense
 * link : https://training.ia-toki.org/problemsets/91/problems/469/
 */

#include <bits/stdc++.h>
#define piii pair<int, pair<int, int> >
#define fi first
#define se second.first
#define th second.second
#define pqiii priority_queue<piii, vector<piii >, greater<piii > >
using namespace std;

string subsoal;
int n, sm, sd;
piii arr[300005];
pqiii pq;

int main() {
	cin>>subsoal;

	long long ret = 0;

	scanf("%d%d%d",&n,&sd,&sm);
	for (int i=0; i<n-1; i++) {
		scanf("%d%d%d", &arr[i].th, &arr[i].se, &arr[i].fi);
		ret += arr[i].se;
		if (i!=0) arr[i].th = max(arr[i].th, arr[i-1].th);
		arr[i].fi = arr[i].fi - arr[i].se;
		arr[i].se*=-1;
	}
	arr[n-1].th = sm;
	arr[n-1].fi = 400000;
	arr[n-1].se = 0;

	int now = sd;

	for (int i=0; i<n; i++) {
		while (now < arr[i].th && !pq.empty()) {
			piii get = pq.top();
			get.se *= -1;
			pq.pop();
			ret += (long long) get.fi;
			now++;
		}
		if (now < arr[i].th) {
			ret = -1;
			break;
		}
		if (i != n-1) pq.push(arr[i]);
	}
	while (!pq.empty() && ret != -1) {
		piii get = pq.top();
		get.se*=-1;
		pq.pop();
		ret += (long long) min(get.fi, 0);
	}

	printf("%lld\n", ret);

}