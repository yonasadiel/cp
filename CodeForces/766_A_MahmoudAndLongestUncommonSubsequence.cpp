#include<bits/stdc++.h>
using namespace std;

string a,b;

int main() {
	cin>>a>>b;
	int n = max(a.length(),b.length());
	if (a!=b) {
		printf("%d\n",n);
	} else {
		printf("-1\n");
	}
	return 0;
}
