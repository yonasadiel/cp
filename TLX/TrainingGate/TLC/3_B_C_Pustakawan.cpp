#include<bits/stdc++.h>
using namespace std;

int main() {
	int jumlah,kartu[1005],sudah[1005],hitung=0;
	scanf("%d",&jumlah);
	for (int i=0; i<jumlah;i++) {
		scanf("%d",&kartu[i]);
		sudah[i]=kartu[i];
	}
	sort(sudah,sudah+jumlah);
	for(int i=0; i<jumlah;i++) {
		if (kartu[i]!=sudah[i]) {
			for (int j=i+1; j<jumlah; j++) {
				if (kartu[j]==sudah[i]) {
//					cout << i<<j <<endl;
					swap(kartu[i],kartu[j]);
					hitung++;
					break;
				}
			}
		}
	}
	
	printf("%d\n",hitung);
}
