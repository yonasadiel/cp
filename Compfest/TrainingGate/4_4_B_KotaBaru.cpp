#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
#include <iostream>
using namespace std;

int n;
vector<int> v[100005];
int dist[100005];

int main() {
	int a,b;
	scanf("%d",&n);
	for (int i=0; i<n-1; i++) {
		scanf("%d%d",&a,&b);
		v[a].push_back(b);
		v[b].push_back(a);
	}

	queue<int> q;
	int maxnode = 1;

	for (int i=0; i<2; i++) {
		memset(dist, -1, sizeof(dist));
		q.push(maxnode);
		dist[maxnode] = 0;

		while(!q.empty()) {
			int cur = q.front();
			q.pop();
			for (int i=0; i<v[cur].size(); i++) {
				int next = v[cur][i];
				if (dist[next] == -1) {
					dist[next] = dist[cur]+1;
					if (dist[next] > dist[maxnode]) {
						maxnode = next;
					}
					q.push(next);
				}
			}
		}	
	}

	printf("%d\n",dist[maxnode]);

}