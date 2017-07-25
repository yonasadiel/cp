#include <cstdio>
#include <algorithm>
#include <vector>
#define dbg if (debug)
using namespace std;

bool debug = false;
int b,q,l,m,buff;
vector<int> arr;

int main() {
	scanf("%d%d%d%d",&b,&q,&l,&m);
	for (int i=0; i<m; i++) {
		scanf("%d",&buff);
		arr.push_back(buff);
	}
	
	sort(arr.begin(),arr.end());
	long long n = (long long) b;
	int cnt = 0;
	
	while (abs(n) <= (long long) l) {
		if (binary_search(arr.begin(),arr.end(),n)) {
			dbg printf("%I64d ada di blacklist\n",n);
		} else {
			dbg printf("%I64d ga ada di blacklist\n",n);
			cnt++;
		}
		n *= (long long) q;
		if (n == (long long) b) {
			if (cnt != 0) printf("inf\n");
			else printf("0\n");
			return 0;
		} else if (q == 0) {
			if (!binary_search(arr.begin(),arr.end(),0)) {
				printf("inf\n");
			} else {
				printf("%d\n",cnt);
			}
			return 0;
		}
	}
	printf("%d\n",cnt);
}
