#include<bits/stdc++.h>
using namespace std;

void gambar(int level) {
	if (level==1) {
		printf("*\n");
	} else {
		gambar(level-1);
		for (int i=0; i<level; i++) {
			printf("*");
		}
		printf("\n");
		gambar(level-1);
	}
	
}

int main() {
	int n;
	scanf("%d",&n);
	gambar(n);
}
