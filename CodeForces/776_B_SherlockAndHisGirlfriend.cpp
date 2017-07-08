#include<bits/stdc++.h>
using namespace std;

int prima[100005];

void shieve() {
	for (int i=0; i<100005; i++) {
		prima[i] = i;
	}
	for (int i=2; i<100005; i++) {
		if (prima[i] == i) {
			for (int j=i*2; j<100005; j+=i) {
				prima[j] = i;
			}
		}
	}
}

int main() {
	int n;
	shieve();
	scanf("%d",&n);
	printf("%d\n",(n<3)?1:2);
	for (int i=0; i<n; i++) {
		if (i==0) printf("%d",(prima[i+2]==i+2)?1:2);
		else printf(" %d",(prima[i+2]==i+2)?1:2);
	}
	printf("\n");
}
/*

2 3 4 5 6 7 8 9 10
1 1 2 1 2 1 3 2  2*/