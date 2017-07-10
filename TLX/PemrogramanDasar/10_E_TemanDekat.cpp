#include<bits/stdc++.h>
using namespace std;

int n,d;
pair<int,int>arr[1500];

int pangkat(int c) {
	if (d==1) return c;
	if (d==2) return c*c;
	if (d==3) return c*c*c;
}

int dekat(pair<int,int> a, pair<int,int> b) {
	return pangkat(abs(a.first-b.first))+pangkat(abs(a.second-b.second));
}

int main() {
	int maks=-1,mini=1e9;
	scanf("%d%d",&n,&d);
	for (int i=0; i<n; i++) {
		scanf("%d%d",&arr[i].first,&arr[i].second);
	}
	for (int i=0; i<n; i++) {
		for (int j=i+1; j<n; j++) {
			maks=max(maks,dekat(arr[i],arr[j]));
			mini=min(mini,dekat(arr[i],arr[j]));
		}
	}
	printf("%d %d\n",mini,maks);
}
