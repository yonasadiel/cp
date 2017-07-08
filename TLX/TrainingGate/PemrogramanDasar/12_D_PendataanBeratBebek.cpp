#include<bits/stdc++.h>
using namespace std;

int arr[100005];

int main() {
	int n,m,a,b;
	scanf("%d",&n);
	for (int i=1; i<=n; i++) {
		scanf("%d",&arr[i]);
	}
	scanf("%d",&m);
	for (int i=0; i<m; i++) {
		scanf("%d%d",&a,&b);
		int awal=1,akhir=n,found1=-1;
		while (awal<=akhir && found1==-1) {
			int tengah=(awal+akhir)/2;
			if (arr[tengah] > a && arr[tengah-1] <= a) {
				found1 = tengah;
			} else if (arr[tengah] > a) {
				akhir = tengah-1;
			} else {
				awal = tengah+1;
			}
		}
		if (found1==-1) found1 = n+1;
		awal=1,akhir=n; int found2=-1;
		while (awal<=akhir && found2==-1) {
			int tengah=(awal+akhir)/2;
			if (arr[tengah] > b && arr[tengah-1] <= b) {
				found2 = tengah;
			} else if (arr[tengah] > b) {
				akhir = tengah-1;
			} else {
				awal = tengah+1;
			}
		}
		if (found2==-1) found2 = n+1;
		printf("%d\n",found2-found1);
	}
}
