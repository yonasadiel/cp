#include<bits/stdc++.h>
using namespace std;

int x,y,p;
long long ret=0;

int main() {
	scanf("%d",&x);
	scanf("%d",&y);
	for (int i=0; i<y; i++) {
		scanf("%d",&p);
		ret+=(x-p);
	}
	printf("%lld",ret+x);
}
