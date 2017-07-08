#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;

int a,b,c,d,e;
vector<int> usb,ps2,gab;

int main() {
	scanf("%d%d%d%d",&a,&b,&c,&d);
	for(int i=0; i<d; i++) {
		int e; string f;
		cin>>e>>f;
		if (f == "USB") {
			usb.push_back(e);
		} else {
			ps2.push_back(e);
		}
	}
	
	sort(usb.begin(), usb.end()); int u = 0;
	sort(ps2.begin(), ps2.end()); int p = 0;
	long long ret = 0;
	int x = 0;
	for (int i = 0; i < usb.size(); i++) {
		if (a > 0) {
			a--; x++;
			ret += (long long) usb[i];	
		} else {
			gab.push_back(usb[i]);
		}
	}
	for (int i = 0; i < ps2.size(); i++) {
		if (b > 0) {
			b--; x++;
			ret += (long long) ps2[i];
		} else {
			gab.push_back(ps2[i]);
		}
	}
	sort(gab.begin(), gab.end());
	
	for (int i = 0; i < min(c, (int) gab.size()); i++) {
		x++;
		ret += (long long) gab[i];
	}
	
	printf("%d %I64d\n",x,ret);
	
}
