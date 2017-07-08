#include<bits/stdc++.h>
using namespace std;
 
int main () {
     
    int a,b;
    char o;
     
    scanf("%d %c %d",&a,&o,&b);
     
    if (o=='+') {
        printf("%d\n",a+b);
    }
    if (o=='-') {
        printf("%d\n",a-b);
    }
    if (o=='*') {
        printf("%d\n",a*b);
    }
    if (o=='<') {
        if (a<b) printf("benar\n"); else printf("salah\n");
    }
    if (o=='>') {
        if (a>b) printf("benar\n"); else printf("salah\n");
    }
    if (o=='=') {
        if (a==b) printf("benar\n"); else printf("salah\n");
    }
    return 0;
}
