#include<bits/stdc++.h>
using namespace std;

int pangkat(int a,int b) {
	int c=1;
	for(int i=1; i<=b; i++) {
		c*=a;
	}
	return c;
}


int main() {
	int a,b,isia=0,isib=0;
	scanf("%d",&a);
	for (int i=0; i<=9; i++ ) {
//		cout << pangkat(10,i) << endl;
		isia+=(a/(pangkat(10,i)))%10;
//		cout << isia <<endl;
	}
	scanf("%d",&b);
	for (int i=0; i<=9; i++ ) {
		isib+=(b/(pangkat(10,i)))%10;
	}
	printf("%d\n",isia*isib);
}
