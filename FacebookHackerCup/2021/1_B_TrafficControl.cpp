#include <iostream>
#include <cstdio>
using namespace std;

void solve(int tc) {
    int n, m, a, b;
    scanf("%d%d%d%d", &n, &m, &a, &b);
    int mp = n + m - 1;
    if (a < mp || b < mp) {
        printf("Case #%d: Impossible\n", tc);
        return;
    }
    printf("Case #%d: Possible\n", tc);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i == 0 && j == 0) printf("%d", a - mp + 1);
            else if (i == 0 && j == m - 1) printf("%d", b - mp + 1);
            else printf("1");
            
            if (j == m - 1) printf("\n");
            else printf(" ");
        }
    }
}

int main() {
    int t;
    scanf("%d", &t);
    for (int i=1; i<=t; i++) solve(i);
}