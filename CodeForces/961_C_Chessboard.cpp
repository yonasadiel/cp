#include <cstdio>
#include <algorithm>
using namespace std;

int n; char a;
int nol[] = {0, 0, 0, 0};
int satu[] = {0, 0, 0, 0};

int main() {
	scanf("%d\n",&n);
	for (int k=0; k<4; k++) {
		for (int i=0; i<n; i++) {
			for (int j=0; j<n; j++) {
				scanf("%c", &a);
				if ((i+j)&1) {
					if (a == '0') { nol[k]++; }
					else { satu[k]++; }
				} else {
					if (a == '0') { satu[k]++; }
					else { nol[k]++; }
				}
			}
			scanf("\n");
		}
		scanf("\n");
	}

	int ans = 100000;
	ans = min(ans, nol[0] + nol[1] + satu[2] + satu[3]);
	ans = min(ans, nol[0] + nol[2] + satu[1] + satu[3]);
	ans = min(ans, nol[0] + nol[3] + satu[1] + satu[2]);
	ans = min(ans, nol[1] + nol[2] + satu[0] + satu[3]);
	ans = min(ans, nol[1] + nol[3] + satu[0] + satu[2]);
	ans = min(ans, nol[2] + nol[3] + satu[0] + satu[1]);
	printf("%d\n", ans);

}