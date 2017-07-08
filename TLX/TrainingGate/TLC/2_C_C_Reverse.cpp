#include<bits/stdc++.h>
using namespace std;

int main () {
	
	char kalimat[100000];
	int c=0;
	
	while (scanf("%c",&kalimat[c])!=EOF) {
		c++;
	}
	c--;
	while (c--) {
		printf("%c",kalimat[c]);
	}
	printf("\n");
	
}
