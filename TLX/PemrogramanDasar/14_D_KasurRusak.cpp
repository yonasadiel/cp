#include<bits/stdc++.h>
using namespace std;

string a,b,c;

int main() {
	cin>>a;
	for (int i=0; i<a.length(); i++) {
		b += a[a.length()-i-1];
	}
	if (a==b) {
		printf("YA\n");
	} else {
		printf("BUKAN\n");
	}
}
