#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, a, b, c=1,d=1;
    scanf("%d%d%d", &n, &a, &b);
    if (b == 0 && a > 0) {
        if (a+2 > n) {
            printf("-1\n");
        } else {
            printf("1 1"); d++;
            for (int i=0; i<a; i++, d++) {
                printf(" %d", i+2);
            }
            while (d < n) {
                printf(" 1");
                d++;
            }
            printf("\n");
        }
        return 0;
    }
    printf("1");
    for (int i=1; i<=b; i++, d++) {
        c <<= 1;
        printf(" %d", c);
    }
    for (int i=1; i<=a; i++, d++) {
        c++;
        printf(" %d", c);
    }
    while (d < n) {
        printf(" %d", 1);
        d++;
    }
    printf("\n");
}