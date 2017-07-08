#include <cstdio>
using namespace std;

int main() {
	int a,b,c,x,y,cnt=0;
	scanf("%d%d%d%d",&a,&b,&c,&x);
	y = x;
	do {
		x = (a*x+b)%c;
		cnt++;
	} while (x!=y);
	printf("%d\n",cnt);
}