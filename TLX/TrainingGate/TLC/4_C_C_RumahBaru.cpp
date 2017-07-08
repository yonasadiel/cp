#include<bits/stdc++.h>
using namespace std;
 
int x[103],y;
int petaa[205][205];
bool cekatas,cekiri,cekanan,cekbawah;
int main() {
    int n;
    memset(petaa,0,sizeof petaa);
    scanf("%d",&n);
    for (int i=0; i<n; i++) {
        scanf("%d",&x[i]);
    }
    for (int i=0; i<n; i++) {
        scanf("%d",&y);
        petaa[x[i]+100][y+100]=1;
    }
    int hitung=0;
    for (int i=0; i<205; i++) {
        for (int j=0; j<205; j++) {
            cekatas=false,cekbawah=false,cekanan=false,cekiri=false;
            //ke atas
            for (int k=i-1; k>=0; k--) {
                if (petaa[k][j]==1) {
                    cekatas=true;
                    break;
                }
            }
            if (!cekatas) continue;
            //ke bawah
            for (int k=i+1; k<205; k++) {
                if (petaa[k][j]==1) {
                    cekbawah=true;
                    break;
                }
            }
            if (!cekbawah) continue;
            //ke kanan
            for (int k=j+1; k<205; k++) {
                if (petaa[i][k]==1) {
                    cekanan=true;
                    break;
                }
            }
            if (!cekanan) continue;
            //ke kiri
            for (int k=j-1; k>=0; k--) {
                if (petaa[i][k]==1) {
                    cekiri=true;
                    break;
                }
            }
            if (!cekiri) continue;
            hitung++;
        }
    }
    cout<<hitung<<endl;
}
