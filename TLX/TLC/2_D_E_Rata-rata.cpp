#include<bits/stdc++.h>
using namespace std;
 
int main () {
     
    double min=1000000,maks=-1000000,koun,jumlah=0;
    int n;
     
    scanf("%d",&n);
    for (int i=0;i<n;i++) {
        scanf("%lf\n",&koun);
        jumlah+=koun;
//      printf("%.2f\n",jumlah);
        if (koun<min) min=koun;
        if (koun>maks) maks=koun;
    }
    printf("%.2lf %.2lf %.2lf\n",min,maks,jumlah/n);
    return 0;
}
