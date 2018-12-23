#include <bits/stdc++.h>
using namespace std;

int n, k;

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &k);
        for (int i = 0; i < n; i++) {
            printf("%c", 'a' + (i % k));
        }
        printf("\n");
    }
}
