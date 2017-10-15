#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

int ja,jb;

int depe[105][105];

int playdp(int jan, int jbn) {
	int &ret=depe[jan][jbn];
	if (ret!=-1) {
		return ret;
	}
	if (jan<=0 && jbn<=0) {
		ret=0;
		return 0;
	}
	ret=0;
	if (jan-2>=0) {
		ret=max(ret,playdp(jan-2,jbn+1));
	}
	if (jbn-2>=0) {
		ret=max(ret,playdp(jan+1,jbn-2));
	}
	ret++;
	return ret;
}

int main() {
	memset(depe,-1,sizeof depe);
	scanf("%d%d",&ja,&jb);
	printf("%d\n",max(0,playdp(ja,jb)-2));
	
}
