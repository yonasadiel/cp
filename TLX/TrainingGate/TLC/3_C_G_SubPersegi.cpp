#include<bits/stdc++.h>
using namespace std;

int jumah;

int main() {
	int n;
	scanf("%d",&n);
	for (int i=1; i<=n; i++) {
		jumah+=i*i;
	}
	printf("%d\n",jumah);

}
