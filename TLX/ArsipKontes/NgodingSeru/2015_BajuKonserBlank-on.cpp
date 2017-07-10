#include<bits/stdc++.h>
using namespace std;

int main() {
	int b,p,l;
	scanf("%d%d%d",&b,&p,&l);
	if (b<=10 && p<=40 && l<=90) {
		cout<<"S"<<endl;
	} else if (b<=14 && p<=60 && l<=120) {
		cout<<"M"<<endl;
	} else if (b<=18 && p<=80 && l<=180) {
		cout<<"L"<<endl;
	} else {
		cout<<"X"<<endl;
	}
}
