#include<bits/stdc++.h>
using namespace std;

int n,k,g,b;

int main() {
	scanf("%d%d%d%d",&n,&k,&g,&b);
	if (g<b) {
		if ((long long) b > (long long) (g+1)*k) {
			printf("NO");
		} else {
			int l = b%(g+1);
			for (int i=0; i<g+1; i++) {
				if (i!=0) printf("G");
				for (int j=0; j<b/(g+1); j++) {
					printf("B");
				}
				if (l>0) {
					printf("B");
					l--;
				}
			}
		}
	} else {
		if ((long long) g > (long long) (b+1)*k) {
			printf("NO");
		} else {
			int l = g%(b+1);
			for (int i=0; i<b+1; i++) {
				if (i!=0) printf("B");
				for (int j=0; j<g/(b+1); j++) {
					printf("G");
				}
				if (l>0) {
					printf("G");
					l--;
				}
			}
		}
	}
	printf("\n");
}
