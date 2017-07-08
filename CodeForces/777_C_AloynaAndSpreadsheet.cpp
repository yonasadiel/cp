#include<bits/stdc++.h>
#define dbg if(debug)
using namespace std;

int n,m;
vector< vector<int> > arr,brr;
int get[100005];
int in;
bool debug = false;

void outbrr() {
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			printf("%d ",brr[i][j]);
		}
		printf("\n");
	}
}
void outget() {
	for (int i=0; i<n; i++) {
		printf("%d\n",get[i]);
	}
}

int main() {
	for (int i=-10; i<=10; i++) {
		cout<<i<<" "<<((i)?"1":"0") <<endl;
	}
	scanf("%d%d",&n,&m);
	for (int i=0; i<n; i++) {
		vector<int> tmpa,tmpb;
		for (int j=0; j<m; j++) {
			scanf("%d",&in);
			tmpa.push_back(in);
			if (i == 0) {
				tmpb.push_back(0);
			} else if (in < arr[i-1][j]) {
				tmpb.push_back(i);
			} else {
				tmpb.push_back(brr[i-1][j]);
			}
		}
		arr.push_back(tmpa);
		brr.push_back(tmpb);
	}
	
	dbg outbrr();
	
	for (int i=0; i<n; i++) {
		get[i] = brr[i][0];
		for (int j=1; j<m; j++) {
			get[i] = min(get[i],brr[i][j]);
		}
	}
	
	int k,l,r;
	scanf("%d",&k);
	for (int i=0; i<k; i++) {
		scanf("%d%d",&l,&r);
		l--; r--;
		if (get[r] <= l) {
			printf("Yes\n");
		} else {
			printf("No\n");
		}
	}
}

