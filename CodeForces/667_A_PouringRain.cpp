#include<bits/stdc++.h>
using namespace std;

double pi=3.14159265358979325;

int main() {
	int d,h,v,e;
	scanf("%d%d%d%d",&d,&h,&v,&e);
	if ((double)v <= (double)e*pi*d*d/4) {
		printf("NO\n");
		return 0;
	}
	double dv= v-(e*pi*d*d/4);
	double ret=pi*d*d*h/4/dv;
	printf("YES\n%.9lf\n",ret);
	return 0;
	
}
