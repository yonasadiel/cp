#include<bits/stdc++.h>
using namespace std;

int arr[76]={4,5,6,2,2,2,2,0,0,
			 3,0,4,7,6,3,3,3,0,0,
			 4,5,0,6,4,1,1,1,0,0,
			 5,5,7,0,8,2,1,1,0,0,
			 6,7,8,6,0,7,1,1,0,0,
			 8,7,5,7,8,0,8,3,0,0,
			 6,8,5,5,8,3,0,3,0,0,
			 7,6,4,2,2,4,4};
int angka[3];

int cari(int x) {
	if (x==123) return 21;
	if (x==124) return 12;
	if (x==125) return 15;
	if (x==126) return 16;
	if (x==127) return 17;
	if (x==128) return 18;
	if (x==134) return 31;
	if (x==135) return 13;
	if (x==136) return 36;
	if (x==137) return 37;
	if (x==138) return 38;
	if (x==145) return 41;
	if (x==146) return 14;
	if (x==147) return 47;
	if (x==148) return 48;
	if (x==156) return 51;
	if (x==157) return 57;
	if (x==158) return 58;
	if (x==167) return 71;
	if (x==168) return 61;
	if (x==178) return 81;
	if (x==234) return 23;
	if (x==235) return 32;
	if (x==236) return 26;
	if (x==237) return 27;
	if (x==238) return 28;
	if (x==245) return 42;
	if (x==246) return 46;
	if (x==247) return 24;
	if (x==248) return 84;
	if (x==256) return 25;
	if (x==257) return 52;
	if (x==258) return 85;
	if (x==267) return 62;
	if (x==268) return 82;
	if (x==278) return 72;
	if (x==345) return 35;
	if (x==346) return 34;
	if (x==347) return 43;
	if (x==348) return 83;
	if (x==356) return 63;
	if (x==357) return 73;
	if (x==358) return 53;
	if (x==367) return 76;
	if (x==368) return 68;
	if (x==378) return 78;
	if (x==456) return 54;
	if (x==457) return 74;
	if (x==458) return 45;
	if (x==467) return 64;
	if (x==468) return 86;
	if (x==478) return 87;
	if (x==567) return 56;
	if (x==568) return 65;
	if (x==578) return 75;
	if (x==678) return 67;
}



int main() {
	int m,d;
	scanf("%d%d",&m,&d);
//while (true) { m=1;d=1;
	while (m--) {
		scanf("%d%d%d",&angka[0],&angka[1],&angka[2]);
		sort(angka,angka+3);
		int y=100*angka[0]+10*angka[1]+angka[2];
		printf("%d %d\n",cari(y)/10,cari(y)%10);
	}
	while (d--) {
		int x,y;
		scanf("%d%d",&x,&y);
		printf("%d\n",arr[x*10+y-12]);
	}
	
	
//	for (int i=12; i<=87; i++) {
//		printf("%d %d\n",i,arr[i-12]);
//	}
//}
	return 0;
}
