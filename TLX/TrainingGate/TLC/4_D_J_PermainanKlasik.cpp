#include<bits/stdc++.h>
using namespace std;

pair <int,pair<int,pair<int,string> > > pasangan;
priority_queue <pasangan> peserta;

int main() {
	int kase,n,m,satu,dua,tiga;
	char nama[10],dicari[10];
	scanf("%n",&kase);
	while (kase--) {
		scanf("%d%d",&n,&m);
		scanf("%s",&dicari);
		while (n--) {
			scanf("%s%d%d%d",&nama,&satu,&dua,&tiga);
			pasangan temp=make_pair(tiga,make_pair(dua,make_pair(satu,nama)));
			peserta.push(temp);
		}
		bool ketemu=false;
		while (m--) {
			if (peserta.top().nama==dicari) {
				printf("YA\n");
				ketemu=true;
				break;
			}
			peserta.pop();
		}
		if (!ketemu) {
			printf("TIDAK\n");
		}
	}
}