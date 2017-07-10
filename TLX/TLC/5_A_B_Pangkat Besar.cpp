#include<bits/stdc++.h>
using namespace std;
 
long long a,b;
bool cek=true;
 
long long hitung(long long bawah, long long atas) {
    if (atas==0) return 1;
    if (atas==1) return bawah;
    long long ret = hitung(bawah,atas/2);
    if (ret>=1000000) {
    	cek=false;
    	ret%=1000000;
    }
    ret=ret*ret;
    if (ret>=1000000) {
    	cek=false;
    	ret%=1000000;
    }
    if (atas%2==0) {
        return ret;
    } else {
        return (ret*bawah);
    }
     
}
 
int main() {
//	while(true) {
	cek=true;
    scanf("%lld%lld",&a,&b);
    long long hasil;
    hasil=hitung(a,b);
    if (hasil>=1000000) {
    	cek=false;
    	hasil%=1000000;
    }
    if (cek) {
        printf("%lld\n",hasil);  	
    } else {
    if (hasil>99999) {
        printf("%lld\n",hasil);
    } else{
        if (hasil>9999) {
            printf("0%lld\n",hasil);
        } else {
            if (hasil>999) {
                printf("00%lld\n",hasil);
            } else {
                if (hasil>99) {
                    printf("000%lld\n",hasil);
                } else {
                    if (hasil>9) {
                        printf("0000%lld\n",hasil);
                    } else {
                        printf("00000%lld\n",hasil);
                    }                       
                }                   
            }               
        }           
    }
	}
//}
     
}
