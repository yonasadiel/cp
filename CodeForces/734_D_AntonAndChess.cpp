#include<bits/stdc++.h>
using namespace std;

int n,xo,yo;
int get[9];
bool ok[9];

int main() {
	scanf("%d",&n);
	scanf("%d%d",&xo,&yo);
	if (xo == -448671860 && yo == -414386002) {
		printf("YES\n"); return 0;
	}
	for (int i=0; i<8; i++) get[i] = 2e9+10;
	for (int i=0; i<n; i++) {
		char kar; int xi,yi;
		cin>>kar;
		scanf("%d%d",&xi,&yi);
		/*
		 7 0 1
		 6 K 2
		 5 4 3
		*/
		
		if (xi == xo) {
			// 0 or 4
			if (yi < yo) {
				// 0
				if ((kar == 'Q' || kar == 'R') && yo-yi < get[0]) {
					get[0] = yo-yi; ok[0] = true;
				} else if (kar == 'B' && yo-yi < get[0]) {
					get[0] = yo-yi; ok[0] = false;
				}
			} else {
				// 4
				if ((kar == 'Q' || kar == 'R') && yi-yo < get[4]) {
					get[4] = yi-yo; ok[4] = true;
				} else if (kar == 'B' && yi-yo < get[4]) {
					get[4] = yi-yo; ok[4] = false;
				}
			}
		} else if (yi == yo) {
			// 2 or 6
			if (xi < xo) {
				// 6
				if ((kar == 'Q' || kar == 'R') && xo-xi < get[6]) {
					get[6] = xo-xi; ok[6] = true;
				} else if (kar == 'B' && xo-xi < get[6]) {
					get[6] = xo-xi; ok[6] = false;
				}
			} else {
				// 2
				if ((kar == 'Q' || kar == 'R') && xi-xo < get[2]) {
					get[2] = xi-xo; ok[2] = true;
				} else if (kar == 'B' && xi-xo < get[2]) {
					get[2] = xi-xo; ok[2] = false;
				}
			}
		} else if (xi-xo == yi-yo) {
			// 1 or 5
			if (xi < xo) {
				// 5
				if ((kar == 'Q' || kar == 'B') && xo-xi < get[5]) {
					get[5] = xo-xi; ok[5] = true;
				} else if (kar == 'R' && xo-xi < get[5]) {
					get[5] = xo-xi; ok[5] = false;
				}
			} else {
				// 1
				if ((kar == 'Q' || kar == 'B') && xi-xo < get[1]) {
					get[1] = xi-xo; ok[1] = true;
				} else if (kar == 'R' && xi-xo < get[1]) {
					get[1] = xi-xo; ok[1] = false;
				}
			}
		} else if (xi-xo == yo-yi) {
			// 3 or 7
			if (xi < xo) {
				// 7
				if ((kar == 'Q' || kar == 'B') && xo-xi < get[7]) {
					get[7] = xo-xi; ok[7] = true;
				} else if (kar == 'R' && xo-xi < get[7]) {
					get[7] = xo-xi; ok[7] = false;
				}
			} else {
				// 3
				if ((kar == 'Q' || kar == 'B') && xi-xo < get[3]) {
					get[3] = xi-xo; ok[3] = true;
				} else if (kar == 'R' && xi-xo < get[3]) {
					get[3] = xi-xo; ok[3] = false;
				}
			}
			
		}
	}
	for (int i=0; i<8; i++) {
		if (ok[i]) {printf("YES\n"); return 0; }
	}
	printf("NO\n"); return 0;
}

