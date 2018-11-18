#include <bits/stdc++.h>
using namespace std;

int n;
int a[105];
int b[105];

int main() {
    scanf("%d", &n);
    for (int i=0; i<n; i++) {
        scanf("%d", &a[i]);
        b[i] = 0;
    }

    for (int i=1; i<n-1; i++) {
        if (a[i] == 0 && a[i-1] == 1 && a[i+1] == 1) {
            b[i-1]++; b[i+1]++;
            b[i] = -1;
        }
    }

    int ans = 0;
    for (int i=0; i<n; i++) {
        if (b[i] == 2 && b[i+1] == -1 && b[i-1] == -1) {
            b[i+1] = 0;
            b[i-1] = 0;
            ans++;
        }
    }

    for (int i=0; i<n; i++) {
        if (b[i] == -1) ans++;
    }

    printf("%d\n", ans);
}