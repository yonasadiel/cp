#include<bits/stdc++.h>
using namespace std;

int arr[100005];

bool komp(int a, int b) {
	return a>b;
}

int main() {
	int n,n1,n2;
	scanf("%d%d%d",&n,&n1,&n2);
	
	if (n1 > n2) swap(n1,n2);
	
	for (int i=0; i<n; i++) {
		scanf("%d",&arr[i]);
	}
	
	sort(arr,arr+n,komp);
	
	long long ret = 0;
	double retu = 0.00000;
	for (int i=0; i<n; i++) {
		ret+=arr[i];
		if (i==n1-1) {
			retu+=(double) ret/n1;
			ret = 0;
		}
		if (i==n1+n2-1) {
			retu+=(double) ret/n2;
			break;
		}
	}
	printf("%.8lf\n",retu);
}
