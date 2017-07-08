#include<bits/stdc++.h>
using namespace std;
/* mengambil sejumlah uang dari saldo dengan presisi 2 angka di belakang koma
   bila saldo kurang, tidak diambil. pengambilan harus kelipatan 5
*/

int main() {
	int ambil;
	float saldo;
	scanf("%d %f",&ambil,&saldo);
	saldo-=0.50;
	if (ambil%5 != 0) {
		saldo+=0.50;
		printf("%.2f\n",saldo);
	} else if (ambil > saldo) {
		saldo+=0.50;
		printf("%.2f\n",saldo);
	} else {
		printf("%.2f\n",saldo-ambil);
	}
	return 0;
}
