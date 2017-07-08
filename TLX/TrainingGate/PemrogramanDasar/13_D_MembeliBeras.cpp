#include<bits/stdc++.h>
using namespace std;

int n,t[10005],x;
pair<int,int> b[10005];
int reti=0;
double ret=0;

bool komp(pair<int,int> a, pair<int,int> c) {
	return (double) a.second / a.first > (double) c.second / c.first;
}

int main() {
	scanf("%d%d",&n,&x);
	if (n>10000) while(1);
	for (int i=0; i<n; i++) {
		scanf("%d",&b[i].first);
	}
	for (int i=0; i<n; i++) {
		scanf("%d",&b[i].second);
	}
	
	sort(b,b+n,komp);
	
	for (int i=0; i<n && x>0; i++) {
		if (b[i].first > x) {
			ret=(double) x*b[i].second/b[i].first;
			break;
		} else {
			reti+=b[i].second;
			x-=b[i].first;
		}
	}
	printf("%.5lf\n",(double)ret+reti);
}
