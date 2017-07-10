#include<bits/stdc++.h>
using namespace std;
	int n,agnka[2000005];

int main() {
	scanf("%d",&n);
	
	for (int i=0; i<n; i++) {
		scanf("%d",&agnka[i]);
	}
	sort(agnka,agnka+n);
	if (n%2!=0) {
		printf("%d\n",agnka[(n/2)]);
	}
	if (n%2==0) {
//		cout << agnka[n/2] << agnka[(n/2)+1] <<endl;
		float medain=(agnka[(n/2)-1]+agnka[(n/2)])/2.00;
		printf("%.2f\n",medain);
	}
}
