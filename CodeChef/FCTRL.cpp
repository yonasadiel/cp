#include<bits/stdc++.h>
using namespace std;

int main() {
	int n,a,b;
	scanf("%d",&n);
	for (int i=0; i<n; i++) {
		scanf("%d",&a);
		b= a/5
 	     + a/25
		 + a/125
		 + a/625
		 + a/3125
		 + a/15625
		 + a/78125
		 + a/390625
		 + a/1953125
		 + a/9765625
		 + a/48828125;
		printf("%d\n",b);
	}
}
