#include<bits/stdc++.h>
using namespace std;

int n,dat[105],p,datsort[105],w;
vector <int> pindah[105];
bool oke[105];
queue <int> kue;

int main() {
	scanf("%d",&n);
	for (int i=0; i<n; i++) {
		scanf("%d",&dat[i]);
		datsort[i]=dat[i];
	}
	for (int i=0; i<n; i++) {
		scanf("%d",&p);
		if (i+p<n) {
			pindah[i].push_back(i+p);
			pindah[i+p].push_back(i);
		}
		if (i-p>=0) {
			pindah[i].push_back(i-p);
			pindah[i-p].push_back(i);
		}
	}
	sort(datsort,datsort+n);
	memset(oke,false,sizeof oke);
	for (int i=0; i<n; i++) {
		if (dat[i]==datsort[i]) {
			oke[i]=true;
			continue;
		}
		bool sudah[105];
		memset(sudah,false,sizeof sudah);
		kue.push(i);
		while (!kue.empty()) {
			int kur=kue.front();
//			cout<<i<<" "<<kur<<endl;
//			cin>>w;
			sudah[kur]=true;
			if (dat[kur]==datsort[i]) {
				oke[i]=true;
//				cout<<"ketem "<<i<<endl;
			}
			kue.pop();
			for (int j=0; j<pindah[kur].size(); j++) {
				if (!sudah[pindah[kur][j]]) kue.push(pindah[kur][j]);
			}
		}		
	}
	for (int i=0; i<n; i++) {
		if (!oke[i]) {
			printf("NO\n");
			return 0;
		}
	}
	printf("YES\n");
}
