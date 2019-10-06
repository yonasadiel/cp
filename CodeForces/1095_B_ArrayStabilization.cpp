#include <bits/stdc++.h>
using namespace std;

int n;
int a[100005];

int solve() {
    for (int i=0; i<n; i++) {
        scanf("%d", &a[i]);
    }
    sort(a, a+n);
    printf("%d\n", min(a[n-1] - a[1], a[n-2] - a[0]));
}

int main () {
    while (scanf("%d", &n) == 1) {
        solve();
    }
}