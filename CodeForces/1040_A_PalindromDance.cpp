#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x[2];
    int a[30], b[30];

    scanf("%d%d%d", &n ,&x[0], &x[1]);
    for (int i=0; i<n; i++) {
        scanf("%d", &a[i]);
        b[n-i-1] = a[i];
    }

    int harga = 0;
    bool bisa = true;
    for (int i=0; i<n; i++) {
        if (a[i] == 2) {
            if (b[i] == 2) {
                harga += min(x[0], x[1]);
            } else {
                harga += x[b[i]];
            }
        } else {
            if (a[i] != b[i] && b[i] != 2) {
                bisa = false;
            }
        }
    }
    if (bisa) {
        printf("%d\n", harga);
    } else {
        printf("-1\n");
    }

}