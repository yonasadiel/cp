#include <bits/stdc++.h>

char subsoal[100];
int N, Q, C, i;

int main() {
    scanf("%s", subsoal);
    scanf("%d %d", &N, &Q);
    int min=1, maks=N;
   
    for (i = 1; i <= Q; i++) {
        scanf("%d", &C);
        if (C-min==0 && maks-C==0) {
        	printf("SELAMAT\n");
        	fflush(stdout);
        } else {
        	if (C-min > maks-C) {
        		maks=C-1;
        		printf("TERLALU BESAR\n");
        		fflush(stdout);
        	} else {
        		min=C+1;
        		printf("TERLALU KECIL\n");
        		fflush(stdout);
        	}
        }
    }

    return 0;
}
