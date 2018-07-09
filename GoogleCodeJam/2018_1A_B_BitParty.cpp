#include <cstdio>
#include <algorithm>
#include <cstring>
#define ll long long
#define INF 999999999999999999
using namespace std;

int r, c;
ll b;
ll m[25], s[25], p[25];

ll dp[10][10][25];

ll play(int pos, int robot, ll bit) {
	ll &ret = dp[pos][robot][bit];
	if (ret == -1) {
		if (robot == r || bit == b || pos ==c) {
			if (bit == b) {
				return 0;
			} else {
				return INF;
			}
		} else {
			ret = play(pos+1, robot, bit);
			for (ll i=1; i<=min(b-bit, m[pos]); i++) {
				ret = min(ret, max(s[pos] * i + p[pos], play(pos+1, robot+1, bit+i)));
			}
		}
	}
	//fprintf(stderr, "%d %d %lld %lld\n", pos, robot, bit, ret);
	return ret;
}

void exec(int tc) {
	memset(dp, -1, sizeof dp);
	scanf("%d%d%d", &r,&b,&c);
	for (int i=0; i<c; i++) {
		scanf("%lld%lld%lld", &m[i], &s[i], &p[i]);
	}
	printf("Case #%d: %lld\n", tc, play(0, 0, 0));


}

int main() {
	int tc;
	scanf("%d", &tc);
	for (int i=1; i<=tc; i++) {
		exec(i);
	}
}