#include <bits/stdc++.h>
 
int main() {
     
    int baris,kolom,matriks[105][105];
    scanf("%d %d",&baris,&kolom);
     
    for (int i=0; i<baris; i++) {
        for (int j=0; j<kolom; j++) {
            scanf("%d",&matriks[i][j]);
        }
    }
    for (int i=0; i<kolom; i++) {
        for (int j=baris-1; j>=0; j--) {
            printf("%d",matriks[j][i]);
            if (j!=0) printf(" ");
        }
        printf("\n");
    }
     
    return 0;
}
