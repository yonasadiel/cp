#include<bits/stdc++.h>
using namespace std;

struct q {
		int x,y,jarak;
		q() { };
		q(int a, int b, int c ) {
			x = a; y = b; jarak = c;
		}
	};

q que[100000];
int pet[100][100];	
	int baris,kolom,posbaris,poskolom;	int head=1,tail=1;
void tambah(int a,int b,int c) {
	if (a>0 && b>0 && a<=baris && b<=kolom){
		if (pet[a][b]==0) {
			head++;
			que[head]=q(a,b,c);
			pet[a][b]=-1;
		}
	}
}

int main() {


	scanf("%d %d",&baris,&kolom);
	
	for(int r=1; r<=baris; r++) {
		for (int c=1; c<=kolom; c++) {
			scanf("%d",&pet[r][c]);
		}
	}
	scanf("%d %d",&posbaris,&poskolom);

	que[1] = q(posbaris,poskolom,1);
	
	while (tail<=head) {
		//check atas kiri bawah kanan tail
		if (que[tail].x == 1 || que[tail].y == 1 || que[tail].x == baris || que[tail].y == kolom){
			printf("%d\n",que[tail].jarak);
			return 0;
		}	
		
		tambah(que[tail].x - 1, que[tail].y, que[tail].jarak + 1);
		tambah(que[tail].x + 1, que[tail].y, que[tail].jarak + 1);
		tambah(que[tail].x, que[tail].y - 1, que[tail].jarak + 1);
		tambah(que[tail].x, que[tail].y + 1, que[tail].jarak + 1);
		tail++;
	}
	
	
	return 0;
}
