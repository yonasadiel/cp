#include<bits/stdc++.h>
using namespace std;
 
int main() {
    int jumlah,kartu[1005],hitung=0;
    scanf("%d",&jumlah);
    scanf("%d",&kartu[0]);
    for (int i=1; i<jumlah;i++) {
        scanf("%d",&kartu[i]);
        for (int j=0; j<i; j++) {
            if (kartu[i-j]<kartu[i-j-1]) {
                swap(kartu[i-j],kartu[i-j-1]);
                hitung++;
            }
        }
    }
    printf("%d\n",hitung);
}
