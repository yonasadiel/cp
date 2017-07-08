#include<bits/stdc++.h>
using namespace std;
 
char kamus[3005][3005];
char baruu[3005][3005];
int dp[3005];
int panjang[3005];
int mini,pendek;

int main() {
//  kosongkan();
    int n;
    scanf("%d",&n);
    for (int i=0; i<n; i++) {
        scanf("%s",&kamus[i]);
        panjang[i]=strlen(kamus[i]);
    }
    
    char kata[3005];
    scanf("%s",&kata);
    pendek=strlen(kata);
//	sort(kamus,kamus+n,komparator);
    memset(dp,0,sizeof dp);
    char baru[3005];
    for (int i=0; i<pendek; i++) {
        mini=999999999;
        int hasil;
        for (int j=0; j<n; j++) {
            if (panjang[j]<i+1) continue;
            dp[j]+=min(abs(kamus[j][i]-kata[i]),26-abs(kamus[j][i]-kata[i]));            
            if (dp[j]<mini) {
                hasil=j;
                mini=dp[j];
            }
        }
    	for (int k=0; k<=i; k++) {
    		printf("%c",kamus[hasil][k]);
    	}
    	printf("\n");
    }
}
