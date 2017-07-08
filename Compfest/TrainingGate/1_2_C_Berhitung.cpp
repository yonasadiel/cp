#include <cstdio>
using namespace std;

int main() {
	int a,b;
	char o;
	scanf("%d %c %d",&a,&o,&b);
	if (o == '+') {
		printf("%d\n",a+b);
	} else if (o == '-') {
		printf("%d\n",a-b);
	} else if (o == '*') {
		printf("%d\n",a*b);
	} else if (o == '/') {
		printf("%d\n",a/b);
	} else if (o == '%') {
		printf("%d\n",a%b);
	}
}