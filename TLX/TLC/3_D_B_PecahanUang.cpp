#include<bits/stdc++.h>
using namespace std;

int main() {
	int uang;
	scanf("%d",&uang);
	if (uang>=1000) {
		printf("1000 ");
		printf("%d\n",uang/1000);
		uang%=1000;
	}
	if (uang>=500) {
		printf("500 ");
		printf("%d\n",uang/500);
		uang%=500;
	}
	if (uang>=200) {
		printf("200 ");
		printf("%d\n",uang/200);
		uang%=200;
	}
	if (uang>=100) {
		printf("100 ");
		printf("%d\n",uang/100);
		uang%=100;
	}
	if (uang>=50) {
		printf("50 ");
		printf("%d\n",uang/50);
		uang%=50;
	}
	if (uang>=20) {
		printf("20 ");
		printf("%d\n",uang/20);
		uang%=20;
	}
	if (uang>=10) {
		printf("10 ");
		printf("%d\n",uang/10);
		uang%=10;
	}
	if (uang>=5) {
		printf("5 ");
		printf("%d\n",uang/5);
		uang%=5;
	}
	if (uang>=2) {
		printf("2 ");
		printf("%d\n",uang/2);
		uang%=2;
	}
	if (uang>=1) {
		printf("1 ");
		printf("%d\n",uang/1);
		uang%=1;
	}
}
