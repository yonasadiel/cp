#include <bits/stdc++.h>
using namespace std;

int n;
int a[200005];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    int genap = 0, ganjil = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] & 1) {
            ganjil += 1;
        } else {
            genap += 1;
        }
    }
    int cnt = min(genap, ganjil);
    genap -= cnt; ganjil -= cnt;
    cnt += ganjil / 2;
    printf("%d\n", cnt);

}