#include <queue>
#include <cstdio>
using namespace std;

int main() {
	int kiamat=1,agnka,total,a,b,tambahan;
	
	priority_queue <int> urut;
	
	while (kiamat!=0) {
		int harga=0;
		scanf("%d",&agnka);
		if(agnka==0) return 0;
		
		for (int i=0; i<agnka; i++) {
			scanf("%d",&tambahan);
			urut.push(tambahan*-1);
		}
		for (int i=1; i<agnka; i++) {
			a=-1*urut.top();
			
			urut.pop();
			b=-1*urut.top();
			urut.pop();

			total=a+b;
			harga+=total;

			urut.push(total*-1);
		}
		total=-1*urut.top();
		urut.pop();
		printf("%d\n",harga);
		
	}
	
	return 0;
}
