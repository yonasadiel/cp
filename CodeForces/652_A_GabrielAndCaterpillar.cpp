#include<bits/stdc++.h>
using namespace std;

int main() {
	int h1, h2, a, b;
	scanf("%d%d%d%d",&h1,&h2,&a,&b);
	if (b >= a && h1+a*8 < h2) {
		printf("-1\n");
		return 0;
	}
	int day = 0;
	h1+=a*8;
	while(h1<h2) {
		day++;
		h1+=a*12-b*12;
	}
	printf("%d\n",day);
}