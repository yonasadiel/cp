#include<bits/stdc++.h>
using namespace std;

int primak[1000005];
 
void cari() {
	int n=2,k=1;
    for(int k=1; k<=1000000; n++) {
//    	cout<<k<<" "<<n<<endl;
    	bool prima=true;
    	for (int i=1; i<k; i++) {
    		if (n%primak[i]==0) {
    			prima=false;
    			break;
    		}
    	}
    	if (prima) {
    		primak[k]=n;
    		k++;
    	}
    }
}



int main() {
    cari();
    int atas,bawah,jumelah;
    scanf("%d",&jumelah);
    for (int i=0; i<jumelah; i++) {
    	scanf("%d%d",&bawah,&atas);
    	int ia=upper_bound(primak,primak+1000000,bawah)-primak;
		int ib=lower_bound(primak,primak+1000000,atas )-primak; 
		for (int j=ia; j<ib; j++) {
			printf("%d\n",primak[j]);
		}
    	
    }
     
}
