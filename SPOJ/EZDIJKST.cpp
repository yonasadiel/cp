#include <bits/stdc++.h>
using namespace std;

stack<pair<int,int> > vertex[10005];

priority_queue<pair<int,int> > dijkstra;

int shortest_path[10005];

void pasang() {
	for (int i=0; i<10005; i++) {
		shortest_path[i]=-1999999999;
	}
}

void kosongi() {
	for (int i=0; i<10005; i++) {
		while(!vertex[i].empty()) vertex[i].pop();
	}
	while(!dijkstra.empty()) dijkstra.pop();
}

int main() {
	int kase;
	scanf("%d",&kase);
	while (kase--) {
		kosongi();
		pasang();
		
		//INPUT edge
		int jumlah_edge,jumlah_vertex;
		scanf("%d%d",&jumlah_vertex,&jumlah_edge);
		for (int i=0; i<jumlah_edge; i++) {
			int a,b,c;
			scanf("%d%d%d",&a, &b, &c);
			vertex[a].push(make_pair(-1*c,b));
		}
		
		//INPUT posisi awal
		int awal,tujuan;
		scanf("%d%d",&awal,&tujuan);
		shortest_path[awal]=0;
		dijkstra.push(make_pair(0,awal));
		
		//PROSES
		while (!dijkstra.empty()) {
			pair<int,int> kuren=dijkstra.top();
			dijkstra.pop();
			while (!vertex[kuren.second].empty()) {
				pair<int,int> kurent=vertex[kuren.second].top();
				vertex[kuren.second].pop();
				if (shortest_path[kurent.second]<kurent.first+shortest_path[kuren.second]) {
					shortest_path[kurent.second]=kurent.first+shortest_path[kuren.second];
					dijkstra.push(kurent);
				}
			}
		}
		
		//OUTPUT
		if (shortest_path[tujuan]!=-1999999999) {
			printf("%d\n",-1*shortest_path[tujuan]);
		} else {
			printf("NO\n");
		}
	}
}
