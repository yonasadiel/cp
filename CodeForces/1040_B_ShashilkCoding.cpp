#include <bits/stdc++.h>
#define ceil(a,b) (a+b-1)/b
using namespace std;

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    int ans = ceil(n, (2*k+1));
    printf("%d\n", ans);
    int i;
    if (n % (2*k+1) == 0) {
        i = k+1;
    } else {
        i = ((n % (2*k+1))/2) + 1;
    }
    for (int j=0; j<ans; j++, i+=2*k+1) {
        printf("%d ", i);
    }
    printf("\n");
}