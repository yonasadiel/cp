#include<bits/stdc++.h>
using namespace std;

int main() {
	int k,a;
	char c;
	scanf("%d %c %d",&k,&c,&a);
	for (int i=0; i<k; i++) {
		for (int j=0; j<k; j++) {
			if (i==j || i==k-j-1) {
				cout<<a;
			} else {
				cout<<c;
			}
		}
		cout<<endl;
	}
}
