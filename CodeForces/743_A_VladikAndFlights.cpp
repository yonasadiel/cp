#include<bits/stdc++.h>
using namespace std;

int n,a,b;
string kal;

int main() {
	scanf("%d%d%d",&n,&a,&b);
	cin>>kal;
	if (kal[a-1] == kal[b-1]) {
		printf("0\n");
	} else {
		printf("1\n");
	}
}
