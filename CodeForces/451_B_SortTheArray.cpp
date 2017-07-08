#include<bits/stdc++.h>
using namespace std;

int ar[100005];
int n;

int main() {
	scanf("%d",&n);
	for (int i=0; i<n; i++) {
		scanf("%d",&ar[i]);
	}
	int last=ar[0];
	int i=1;
	int start=-1,end=-1;
	bool bisa=true;
	while (i<n) {
		if (ar[i]<last) {
			start=i-1;
			last=ar[i];
			break;
		}
		last=ar[i];
		i++;
	}
	if (start==-1) {
		printf("yes\n1 1\n");
		return 0;
	}
	while (i<n) {
		if (ar[i]>last) {
			end=i-1;
			last=ar[i];
			break;
		}
		last=ar[i];
		i++;
	}
	if (end==-1) {
		end=n-1;
	}
	if (start>0 && ar[end]<ar[start-1]) {
		printf("no\n");
		return 0;
	}
	if (end<n-1 && ar[start]>ar[end+1]) {
		printf("no\n");
		return 0;
	}
	while (i<n) {
		if (ar[i]<last) {
			printf("no\n");
			last=ar[i];
			return 0;
		}
		last=ar[i];
		i++;
	}
	printf("yes\n%d %d\n",start+1,end+1);
}
