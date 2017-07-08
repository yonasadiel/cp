#include<bits/stdc++.h>
using namespace std;
/* menghitung ada berapa angka yang habis dibagi k
*/

int main() {
	int n,k,a,hitung=0;
	scanf("%d%d",&n,&k);
	for (int i=0; i<n; i++) {
		scanf("%d",&a);
		if (a % k == 0 ) {
			hitung++;
		}
	}
	printf("%d\n",hitung);
}
