#include <bits/stdc++.h>
using namespace std;

int n;
int a[20];
int ans = 1;

void cek(int lo, int hi) {
    if (hi - lo == 1) return;
    bool sorted = true;
    for (int i=lo+1; i<hi; i++) {
        if (a[i] < a[i-1]) sorted = false;
    }
    if (sorted) ans = max(ans, hi - lo);
    cek(lo, (lo + hi) / 2);
    cek((lo + hi) / 2, hi);
}

int main() {
    scanf("%d", &n);
    for (int i=0; i<n; i++) {
        scanf("%d", &a[i]);
    }

    cek(0, n);
    printf("%d\n", ans);
}
