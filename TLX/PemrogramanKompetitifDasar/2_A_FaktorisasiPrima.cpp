#include<bits/stdc++.h>
using namespace std;

int main() {
	
	int agnka;
	scanf("%d",&agnka);
	if (agnka==0) {printf("0"); return 0;}
	if (agnka==1) {printf("1"); return 0;}
	for (int i=2; i<=agnka; i++) {
		int pangkat=1;
		if (agnka%i==0) {
			printf("%d",i);
			agnka/=i;		
			while (agnka%i==0) {
				agnka/=i;
				pangkat++;
			}
			if (pangkat>1) {
				printf("^%d",pangkat);
			}
			if (agnka!=1) printf(" x ");
		}
	}
	printf("\n");
	return 0;
}
