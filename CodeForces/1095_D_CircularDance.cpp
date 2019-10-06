#include <bits/stdc++.h>
using namespace std;

int n;
int a[200005];
int b[200005];
int ne[200005];

int solve() {
    for (int i=0; i<n; i++) {
        scanf("%d%d", &a[i], &b[i]);
        a[i]--;
        b[i]--;
    }
    if (n == 3) {
        printf("1 2 3\n");
        return 0;
    }
    for (int i=0; i<n; i++) {
        if (a[a[i]] == b[i] || b[a[i]] == b[i]) {
            ne[i] = a[i];
        } else {
            ne[i] = b[i];
        }
    }
    int i = 0;
    do {
        if (i != 0) printf(" ");
        printf("%d", i+1);
        i = ne[i];
    } while(i != 0);
    printf("\n");
}

int main () {
    while (scanf("%d", &n) == 1) {
        solve();
    }
}