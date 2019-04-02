#include <bits/stdc++.h>
using namespace std;

int n;
int a[20];

int main() {
    int ans = 0, n, x;
    scanf("%d", &n);
    for (int i=0; i<n; i++) {
        scanf("%d", &a[i]);
    }
    ans = a[2];
    sort(a, a+n);
    ans ^= a[0];
    printf("%d\n", ans + 2);
}