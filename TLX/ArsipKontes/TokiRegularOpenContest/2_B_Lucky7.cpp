#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    printf("%d\n", n-1);
    printf("1");
    for (int i=0; i<n-3; i++) {
        printf(" %d", 1);
    }
    printf(" 2\n");
}