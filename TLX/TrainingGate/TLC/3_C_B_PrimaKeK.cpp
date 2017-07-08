#include<bits/stdc++.h>
using namespace std;

int primak[77777];
 
void cari() {
	int n=2,k=1;
    for(int k=1; k<=77777; n++) {
            int cek=2;
            bool prima=true;
            while(cek<=sqrt(n)) {
                if (n%cek==0) {
                    prima=false;
                    break;
                }
                cek++;
            }
            if (prima) {primak[k]=n; k++; }
    }	
}



int main() {
    cari();
    int k,jumelah;
    scanf("%d",&jumelah);
    for (int i=0; i<jumelah; i++) {
    	scanf("%d",&k);
    	printf("%d\n",primak[k]);    	
    	
    }
     
}
