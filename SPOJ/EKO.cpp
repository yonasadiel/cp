#include <bits/stdc++.h>
using namespace std;

int n,t;
long long arr[1000005];

bool komp(int a, int b) {
	return a>b;
}

int main() {
	cin>>n>>t;
	for (int i=0; i<n; i++) {
		scanf("%lld",&arr[i]);
	}
	arr[n]=0;
	sort(arr,arr+n,komp);
	
	long long cnt=0;
	for (int i=arr[0], j=0; ; i--) {
		while (i<=arr[j]-1) {
			j++;
		}
		cnt+=j;
		if (cnt>=t) {
			cout<<i<<endl;
			break;
		}
//		cout<<"ketinggian "<<i<<" menghasilkan "<<cnt<<endl;
	}
}
