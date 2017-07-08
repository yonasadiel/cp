#include<bits/stdc++.h>
using namespace std;

int s,a,b;
int tk,to;
int p,d;

int main() {
	scanf("%d%d%d",&s,&a,&b);
	scanf("%d%d",&tk,&to);
	scanf("%d%d",&p,&d);
	
	
	//benerin orang
	if (b < a) {
		b = (s-b) + s;
		a = (s-a) + s;
	}
	
	//benerin kereta
	if (d==-1) {
		p = (s-p) + s;
	}
	if (p>a) {
		p-=2*s;
	}
	
	printf("%d\n",min((b-a)*to,(b-p)*tk));
	return 0;
	
	//kalo jalan lebih cepet
	if (to <= tk || (b-p)*tk >= (b-a)*to) {
		printf("%d\n",to*(b-a));
	} else {
		double t1 = (double) (a-p)/(tk-to);
		cout<<t1<<endl;
		double t2 = (double) tk*(b-a-to*t1);
		printf("%.7lf\n",t1+t2);
	}
	
}
