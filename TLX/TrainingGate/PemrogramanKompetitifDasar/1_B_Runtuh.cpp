#include<bits/stdc++.h>
using namespace std;

int r,c;
char pet[30][30];

void output() {
	for (int i=1; i<=r; i++) {
		for (int j=1; j<=c; j++) {
			printf("%c",pet[i][j]);
		}
		printf("\n");
	}
}

int main() {
	scanf("%d%d",&r,&c);
	for (int i=1; i<=r; i++) {
		for (int j=0; j<=c; j++) {
			scanf("%c",&pet[i][j]);
		}
	}
	
	bool loop = true;
	
	while(loop) {
		loop = false;
		int bottom = -1;
		int k = 0;
		
		for (int i=1; i<=r; i++) {
			int cnt = 0;
			for (int j=1; j<=c; j++) {
				if (pet[i][j] == '1') {
					cnt++;
				}
			}
			
			if (cnt == c) {
				k++;
				loop = true;
				
				for (int j=1; j<=c; j++) {
					pet[i][j] = '0';
				}
				
				bottom = max(i, bottom);
				
			}
		}
		
		if (loop) {
			int cnt = 0;
			for (int j=1; j<=c; j++) {
				for (int i=1; i<=bottom; i++) {
					if (pet[i][j] == '1') {
						cnt++;
						pet[i][j] = '0';
					}
				}
				
				int dest = bottom-1;
				for (int i = bottom; i<=r; i++) {
					if (pet[i][j] == '0') {
						dest++;
					} else {
						break;
					}
				}
				
				for (int i = dest; i>=0, cnt>0; i--) {
					pet[i][j] = '1';
					cnt--;
				}
			}
		}
	}
	
	output();
}
