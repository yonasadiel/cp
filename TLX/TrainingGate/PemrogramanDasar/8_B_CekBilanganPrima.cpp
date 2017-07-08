#include<bits/stdc++.h>
using namespace std;
 
int main() {
    int n,a;
    scanf("%d",&n);
    for (int i=0; i<n; i++) {
    	scanf("%d",&a);
        if (a>1) {
            int cek=2;
            bool prima=true;
            while(cek<=sqrt(a)) {
                if (a%cek==0) {
                    printf("BUKAN\n"); prima=false;
                    break;
                }
                cek++;
            }
            if (prima) printf("YA\n");
         
        } else {
        printf("BUKAN\n");
    	}
    }
     
}
