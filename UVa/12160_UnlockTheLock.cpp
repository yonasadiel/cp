#include <bits/stdc++.h>
using namespace std;

int awal=1,tujuan=1,jumlah=1,pilihan[15],head,tail;
bool sudah[10000];
struct q {
		int nilai,jarak=0;
		q() { };
		q(int a, int b) {
			nilai = a; jarak = b;
		}
	};
q kuren;
	
void tambah() {
	kuren.jarak++;
	if ((kuren.nilai%10000)!= tujuan) {
		for (int i=1; i<=jumlah; i++) {
			kuren.nilai=kuren.nilai+pilihan[i];
			if (sudah[kuren.nilai]) tambah();
		}
	}
	else {
		printf("%d\n",kuren.jarak%10000);
	}
	
	
}

int main() {
	memset(sudah,false,sizeof(sudah));
	
	//L
	while ((awal!=0)&&(tujuan!=0)&&(jumlah!=0)){
		if ((awal==0)&&(tujuan==0)&&(jumlah==0)) break;
		printf("hh");
		scanf("%d %d %d",&awal,&tujuan,&jumlah);
		for (int i=1; i<=jumlah; i++) {
			scanf("%d",&pilihan[i]);
		}
		
		kuren=q(awal,-1);		

		tambah();
		
	}	
}

