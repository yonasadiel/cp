#include<bits/stdc++.h>
using namespace std;

int n;
int arr[1000];
vector<long long >v;

int main() {
	scanf("%d",&n);
	for (int i=1; i<=n; i++) {
		scanf("%d",&arr[i]);
	}
	
	bool sudah[1005];
	for (int i=1; i<=n; i++) sudah[i] = false;
	
	long long reta=1, retb=1;
	for (int i=1; i<=n; i++) {
		if (!sudah[i]) {
			int j=i;
			long long cycle = 1;
			sudah[i] = true;
			while (arr[j] != i) {
				j = arr[j];
				if (sudah[j]) {
					printf("-1\n",i,j);
					return 0;
				}
				sudah[j] = true;
				cycle++;
			}
			if (cycle % 2 == 0) cycle/=2;
		//	cout<<i<<" "<<cycle<<endl;
			v.push_back(cycle);
		}
	}
	
	if (v.size() > 0) {
		reta = v[0];
		retb = v[0];
		for (int i=1; i<v.size(); i++) {
			reta /= __gcd(reta,v[i]);
			reta *= v[i];
		}
	} else {
		while (1);
	}
	
	printf("%I64d\n",reta);
}

/*
8
2 3 4 1 6 5 7 8
2

8
2 3 4 5 6 1 7 8


*/
