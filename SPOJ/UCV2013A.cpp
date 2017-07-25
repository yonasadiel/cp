#include <cstdio>
#define MOD 1000000007
using namespace std;

long long n,l;
long long pwr, lstpwr;
long long ans;

int main() {
	scanf("%I64d%I64d",&n,&l);
	while (n!=0 || l!=0) {
		ans = 0; lstpwr = 1;
		for (long long i=1; i<=l; i++) {
			pwr = (lstpwr * n) % MOD;
			ans = (ans + pwr) % MOD;
			lstpwr = pwr;
			if (ans < 0) printf("ans neg\n");
			if (pwr < 0) printf("pwr neg\n");
			if (lstpwr < 0) printf("lstpwr neg\n");
		}
		printf("%I64d\n",ans);

		scanf("%I64d%I64d",&n,&l);
	}
	return 0;
}