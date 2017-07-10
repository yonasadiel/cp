#include<bits/stdc++.h>
using namespace std;

int r,c,x;
int arr[25][25];

pair<int,int> tocell(int a) {
	return make_pair(a/c,a%c);
}

int tonum(pair<int,int> a) {
	return a.first*c+a.second;
}

int main() {
	memset(arr,-1,sizeof arr);
	scanf("%d%d",&r,&c);
	int le=0, ri=r*c-1;
	for (int i=0; i<r*c; i++) {
		scanf("%d",&x);
		if (x==2) {
			printf("%d %d\n",tocell(ri).first+1,tocell(ri).second+1);
			ri--;
		} else {
			printf("%d %d\n",tocell(le).first+1,tocell(le).second+1);
			le++;
		}
		fflush(stdout);
	}
}
