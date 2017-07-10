#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	scanf("%d",&n);
	int jam=n/3600;
	int menit=(n-3600*jam)/60;
	int detik=(n-3600*jam)-60*menit;
	printf("%d\n%d\n%d\n",jam,menit,detik);
}
