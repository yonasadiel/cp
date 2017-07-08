#include<bits/stdc++.h>
using namespace std;

int arr[100005], brr[100005], prr[100005], crr[100005], inv[100005];
bool debug = false;

int main() {
	int n,l,r;
	scanf("%d%d%d",&n,&l,&r);
	for (int i=0; i<n; i++) {
		scanf("%d",&arr[i]);
		arr[i]*=-1;
	}
	for (int i=0; i<n; i++) {
		scanf("%d",&prr[i]);
		inv[i] = prr[i]-1;
		brr[prr[i]-1] = arr[i];
	}
	int mini = l+brr[0];
	crr[0] = l;
	if (debug) cout<<mini<<endl;
	bool bisa = true;
	for (int i=1; i<n; i++) {
		int intended = max(mini+1,l+brr[i]);
		crr[i] = intended - brr[i];
		if (crr[i] > r) {
			bisa = false;
			break;
		}
		mini = intended;
		if (debug) cout<<mini<<endl;
	}
	if (bisa) {
		printf("%d",crr[inv[0]]);
		for (int i=1; i<n; i++) {
			printf(" %d",crr[inv[i]]);
		}
		printf("\n");
	} else {
		printf("-1\n");
	}
}
