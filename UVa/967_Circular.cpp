#include<bits/stdc++.h>
using namespace std;
int c[55]={2,3,5,7,11,13,17,31,37,71,73,79,97,113,131,197,199,311,337,373,719,733,919,971,991,1193,1931,3119,3779,7793,7937,9311,9377,11939,19391,19937,37199,39119,71993,91193,93719,93911,99371,193939,199933,319993,331999,391939,393919,919393,933199,939193,939391,993319,999331};
int main(){while(true){int b,a;scanf("%d",&b);if (b==-1) {return 0;}scanf("%d",&a);int hitung=0;for (int m=0; m<55; m++){if (c[m]>a)break;if(c[m]>=b)hitung++;}if(hitung==0)printf("No Circular Primes.\n");if (hitung==1) printf("1 Circular Prime.\n");if (hitung>1) printf("%d Circular Primes.\n",hitung);}}
