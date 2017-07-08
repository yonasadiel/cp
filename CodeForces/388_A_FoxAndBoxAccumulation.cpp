#include<bits/stdc++.h>
using namespace std;

int kuat[105],ipile[105];
int n,masih=0,pile=0,minimum=101;
int kurkuat;

int main() {
	scanf("%d",&n);
	for (int i=0; i<n; i++) {
		scanf("%d",&kuat[i]);
	}
	sort(kuat,kuat+n);
	memset(ipile,0,sizeof ipile);
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			if (ipile[j]<=kuat[i]) {
				if (ipile[j]==0) {
					pile++;
				}
				ipile[j]++;
				break;
			}
		}
	}
	printf("%d\n",pile);
}
