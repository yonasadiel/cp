#include<bits/stdc++.h>
using namespace std;

string subsoal;
char ch[4][4];
int kasus;
int p[10];
int a,b,c,d,e,f,g,h,i;

int ubah(char cc) {
	if (cc=='s') return 0;
	if (cc=='p') return 3;
	if (cc=='g') return 2;
	if (cc=='d') return 1;
}

int main() {
	cin>>subsoal;
	scanf("%d",&kasus);
	while(kasus--) {
		for (int j=1; j<=3; j++) {
			for (int k=0; k<=3; k++) {
				scanf("%c",&ch[j][k]);
			}
		}
		a=ubah(ch[1][1]); b=ubah(ch[1][2]); c=ubah(ch[1][3]);
		d=ubah(ch[2][1]); e=ubah(ch[2][2]); f=ubah(ch[2][3]);
		g=ubah(ch[3][1]); h=ubah(ch[3][2]); i=ubah(ch[3][3]);
		
		p[1]=(3*a+2*b+3*c+2*d+2*e+1*f+3*g+1*h    )%4;
		p[2]=(3*a+3*b+3*c+3*d+3*e+3*f+2*g    +2*i)%4;
		p[3]=(3*a+2*b+3*c+1*d+2*e+2*f    +1*h+3*i)%4;
		p[4]=(3*a+3*b+2*c+3*d+3*e    +3*g+3*h+2*i)%4;
		p[5]=(3*a+2*b+3*c+2*d+1*e+2*f+3*g+2*h+3*i)%4;
		p[6]=(2*a+3*b+3*c    +3*e+3*f+2*g+3*h+3*i)%4;
		p[7]=(3*a+1*b    +2*d+2*e+1*f+3*g+2*h+3*i)%4;
		p[8]=(2*a    +2*c+3*d+3*e+3*f+3*g+3*h+3*i)%4;
		p[9]=(    1*b+3*c+1*d+2*e+2*f+3*g+2*h+3*i)%4;
		
		for (int i=1; i<=9; i++) {
			for (int j=0; j<p[i]; j++) {
				printf("%d",i);
			}
		}
		printf("\n");
	}
	
}
