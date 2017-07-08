#include<bits/stdc++.h>
using namespace std;

int n;
int ao=0,bo=0,co=0,an,bn,cn;

int main() {
	scanf("%d",&n);
	
	for (int i=0; i<n; i++) {
		scanf("%d%d%d",&an,&bn,&cn);
		ao+=an;
		bo+=bn;
		co+=cn;
	}
	if (ao == 0 && bo == 0 && co == 0) {
		printf("YES\n");
	} else {
		printf("NO\n");
	}
}
