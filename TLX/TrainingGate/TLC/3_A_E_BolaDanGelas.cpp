#include<bits/stdc++.h>
using namespace std;

int main() {
	int gelas[100005],ditanya,tanya,n,x,a,b;
	for (int i=1; i<=100000;i++) {
		gelas[i]=i;
	}
	scanf("%d %d",&n,&x);
	for (int i=0; i<x; i++) {
		scanf("%d %d",&a,&b);
		swap(gelas[a],gelas[b]);
	}
	scanf("%d",&tanya);
	for (int i=0; i<tanya;i++) {
		scanf("%d",&ditanya);
		printf("%d\n",gelas[ditanya]);
	}
}
