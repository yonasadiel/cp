#include<bits/stdc++.h>
using namespace std;
int sudah[1005],belum[1005];
int main() {
	int n;
		
	 while ((scanf("%d",&n))>0){
		int cek=0;
		
		
		for (int i=0;i<n;i++) {
			scanf("%d",&belum[i]);
			sudah[i]=belum[i];
		}
		
		for (int i=1;i<n;i++) {
			for (int k=0; k<=i-1;k++) {			
				if (belum[i-k]<belum[i-1-k]) {
					cek++;
					swap(belum[i-k],belum[i-k-1]);						
				}
			}				
		}
	
	 
		printf("Minimum exchange operations : %d\n",cek);
		
		
		
	}
	
	return 0;	
}
