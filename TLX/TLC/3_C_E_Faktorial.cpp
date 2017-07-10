#include<bits/stdc++.h>
using namespace std;

int main() {
	int n; scanf("%d",&n);
	int kampret=n/5;
	if (n>=25) kampret+=n/25;
	if (n>=125) kampret+=n/125;
	if (n>=625) kampret+=n/625;
	if (n>=3125) kampret+=n/3125;
	printf("%d\n",kampret);
}
