#include<bits/stdc++.h>
using namespace std;

int agama[50005];
bool sama[50005];

int cari(int n) {
	if (agama[n]==n) {
		return n;
	}
	agama[n]=cari(agama[n]);
	return agama[n];
}

bool cek(int a, int b) {
	int x=cari(a);
	int y=cari(b);
	if (x==y) {
		return false;
	}
	return true;
}

void gabung(int a, int b) {
	int x=cari(a);
	int y=cari(b);
	if (x!=y) {
//		cout<<"agama[x]=
		agama[x]=y;
	}
}

int main() {
	int kase=1;
	while (true) {
		memset(sama,false,sizeof sama);
		int n,m;
		scanf("%d%d", &n,&m);
		if (n==0 && m==0) {
			return 0;
		}
		for (int i=1; i<=n; i++) {
			agama[i]=i;
		}
		while (m--) {
			int a,b;
			scanf("%d%d",&a,&b);
			gabung(a,b);
		}
		int hitung=0;
		for (int i=1; i<=n; i++) {
			if (!sama[cari(i)]) {
				hitung++;
				sama[cari(i)]=true;
			}
		}
		printf("Case %d: %d\n",kase,hitung);
		kase++;
	}
}
