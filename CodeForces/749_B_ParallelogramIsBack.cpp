#include<bits/stdc++.h>
using namespace std;

int main() {
	int a,b,c,d,e,f,g,h;
	scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f);
	
	printf("3\n");
	g = e-a+c; h = f-b+d;
	printf("%d %d\n",g,h);
	g = c-e+a; h = d-f+b;
	printf("%d %d\n",g,h);
	g = e-c+a; h = f-d+b;
	printf("%d %d\n",g,h);
}
