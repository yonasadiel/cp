#include<bits/stdc++.h>
using namespace std;
 
int main() {
    int n;
    while(scanf("%d",&n)!=EOF) {
        if (n>1) {
                int cek=2;
            bool prima=true;
            while(cek<=sqrt(n)) {
                if (n%cek==0) {
                    printf("TIDAK\n"); prima=false;
                    break;
                }
                cek++;
            }
            if (prima) printf("YA\n");
         
        } else {
        	printf("TIDAK\n");
    	}
    }
     
}
