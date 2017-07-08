#define fi first
#define se second
#include<bits/stdc++.h>
using namespace std;

int n;
int belum[100005];
int posisi[100005];
int swap1[500005];
int swap2[500005];
int cntswap=0;
bool p[100005];
vector<int> prima;

void shieve() {
	for (int i=1; i<100005; i++) {
		p[i]=true;
	}
	for (int i=2; i*i<100005; i++) {
		if (p[i]) {
			prima.push_back(i);
			for (int j=i*2; j<100005; j+=i) {
				p[j]=false;
			}
		}
	}
}

int main() {
	shieve();
	scanf("%d",&n);
	for (int i=0; i<n; i++) {
		scanf("%d",&belum[i]);
		posisi[belum[i]]=i;
	}
//	char dump;
	int hitung=0;
	for (int i=0; i<n; ) {
		while (belum[i]!=i+1) {
			int tukar=upper_bound(prima.begin(), prima.end(), posisi[i+1]-i+1)-prima.begin()-1;

			if (tukar<0 ) { while(1){}}
			int xyz=posisi[i+1];
			int zyx=posisi[i+1]-prima[tukar]+1;
			if (tukar<0 || xyz<0 || zyx<0 || belum[xyz]<0 || belum[zyx]<0) { while(1){}}
//			cout<<xyz<<" "<<zyx<<endl;
			swap(belum[xyz],belum[zyx]);
			swap(posisi[belum[xyz]],posisi[belum[zyx]]);
			
//			for (int ss=0; ss<n; ss++) {
//				cout<<belum[ss]<<" ";
//			}
//			cout<<endl;
			if (xyz>zyx) swap(xyz,zyx);
			swap1[hitung]=xyz+1;
			swap2[hitung]=zyx+1;
			hitung++;
			if (hitung>=500000) { while(1){}}
		}
		i++;
//		cin>>dump;
	}
	printf("%d\n",hitung);
	for(int i=0; i<hitung; i++) {
		printf("%d %d\n",swap1[i],swap2[i]);
	}
}
