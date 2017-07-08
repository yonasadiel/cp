#include <cstdio>
using namespace std;

int main() {
	int a,b,x,y;
	scanf("%d%d%d%d",&a,&b,&x,&y);
	while (x <= y) {
		printf("%d\n",x);
		x = x*a+b;
	}
}