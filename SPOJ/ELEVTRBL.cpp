#include <cstring>
#include <queue>
#include <cstdio>
using namespace std;

int f,s,g,u,d;
int flo[1000005];
queue<int> antri;

bool valid (int a) {
	return a>0 && a<=f;
}

int main() {
	scanf("%d%d%d%d%d",&f,&s,&g,&u,&d);
	memset(flo,-1,sizeof flo);
	antri.push(s);
	flo[s]=0;
	
	while(!antri.empty()) {
		int cur=antri.front();
//		cout<<cur<<" "<<flo[cur]<<endl;
		antri.pop();
		//up
		if (valid(cur+u) && flo[cur+u]==-1) {
			antri.push(cur+u);
			flo[cur+u]=flo[cur]+1;
		}
		//down
		if (valid(cur-d) && flo[cur-d]==-1) {
			antri.push(cur-d);
			flo[cur-d]=flo[cur]+1;
		}
	}
	if (flo[g]==-1) {
		printf("use the stairs\n");
		return 0;
	}
	printf("%d\n",flo[g]);
}
