#include<bits/stdc++.h>
using namespace std;

char karak[1000005];
int dipake[300];

int main() {	
//while(true) {
	int n,m;
	scanf("%d %d", &n,&m);
	memset(dipake,0,sizeof dipake);
	
	for (int i=0; i<=n; i++) {
		scanf("%c", &karak[i]);
	}
	
	int jumlah=0,head=0,tail=1,hitung=0,angka,hitungmaks=0;
	while (head<=n) {		
		cout<<hitung<< karak[head]<<jumlah<<endl;
		if (jumlah<=m) {
			hitung++;	
			head++;
			angka=karak[head];
			if (dipake[angka]==0) {
				jumlah++;
			}
			dipake[angka]++;
		} else {
			if (tail!=0) {
				angka=karak[tail];
				dipake[angka]--;
				if (dipake[angka]<=0) {
					jumlah--;
				}
			}
			tail++;
			hitung--;
		}
		if (jumlah<=m) {
			hitungmaks=max(hitungmaks,hitung);
			if (hitungmaks>n) hitungmaks=n;			
		}
	}
	printf("%d\n",hitungmaks);
}
