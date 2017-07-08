#include<bits/stdc++.h>
using namespace std;

int reverse(int x) {
    int temp = x;
    int ret  = 0;

    while (temp > 0) {
        ret  = (ret * 10) + (temp % 10);
        temp = temp / 10;
    }

    return ret;
}

int main () {
	
	int a,b;
	scanf("%d %d",&a,&b);
	printf("%d\n",reverse(reverse(a)+reverse(b)));
	

	
}
