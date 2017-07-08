#include<bits/stdc++.h>
using namespace std;

int n;
int edge[500005][2];
vector<int> way[500005];
int arr[500005];
bool c[100005];
bool ct[100005];

int main() {
	memset(c,false,sizeof c);
	memset(ct,false,sizeof ct);
	scanf("%d",&n);
	for (int i=0; i<n-1; i++) {
		scanf("%d%d",&edge[i][0],&edge[i][1]);
		way[edge[i][0]].push_back(edge[i][1]);
		way[edge[i][1]].push_back(edge[i][0]);
	}
	for (int i=1; i<=n; i++) {
		scanf("%d",&arr[i]);
	}
	int cek1=-1,cek2;
	for (int i=0; i<n-1; i++) {
		if (arr[edge[i][0]] != arr[edge[i][1]]) {
			if (cek1 == -1) {
				cek1 = edge[i][0];
				cek2 = edge[i][1];
			}
			c[edge[i][0]] = true;
			c[edge[i][1]] = true;
			ct[edge[i][0]] = true;
			ct[edge[i][1]] = true;
		}
	}
	if (cek1 == -1) {
		printf("YES\n1\n");
		return 0;
	}
	for (int i=0; i<way[cek1].size(); i++) {
		c[way[cek1][i]] = false;
	}
	bool bisa = true;
	for (int i=1; i<=n; i++) {
		if (i!=cek1) bisa = bisa && !c[i];
	}
	if (bisa) {
		printf("YES\n%d\n",cek1);
		return 0;
	}
	for (int i=0; i<way[cek2].size(); i++) {
		ct[way[cek2][i]] = false;
	}
	bisa = true;
	for (int i=1; i<=n; i++) {
		if (i!=cek2) bisa = bisa && !ct[i];
	}
	if (bisa) {
		printf("YES\n%d\n",cek2);
		return 0;
	}
	
	printf("NO\n");
}
