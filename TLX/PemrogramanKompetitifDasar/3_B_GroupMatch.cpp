#include<bits/stdc++.h>
using namespace std;

int n;
int arr[10];
map <vector<int> , bool> cek;

void generate(int a, int b, vector<int> tmp) {
	if (b == n) {
		cek[tmp] = true;
		return;
	}
	
	//printf("%d %d\n",a,b);
	//cin.get();
	
	vector<int> percase;
	
	// A MENANG
	percase = tmp;
	percase[a] += 3;
	if (b == n-1) generate(a+1,a+2,percase);
	else generate(a,b+1,percase);
	
	// B MENANG
	percase = tmp;
	percase[b] += 3;
	if (b == n-1) generate(a+1,a+2,percase);
	else generate(a,b+1,percase);
	
	// SERI
	percase = tmp;
	percase[a] += 1; percase[b] += 1;
	if (b == n-1) generate(a+1,a+2,percase);
	else generate(a,b+1,percase);
}

int main() {	
	int t;
	scanf("%d",&t);
	while(t--) {
		cek.clear();
		
		scanf("%d",&n);
		
		vector<int> baru;
		for (int i=0; i<n; i++) {
				baru.push_back(0);
		}
		
		generate(0,1,baru);
		
		int temp;
		vector<int> dicek;
		for (int i=0; i<n; i++) {
			scanf("%d",&temp);
			dicek.push_back(temp);
		}
		
		if (cek.count(dicek) > 0) {
			printf("YES\n");
		} else {
			printf("NO\n");
		}
	}
}
