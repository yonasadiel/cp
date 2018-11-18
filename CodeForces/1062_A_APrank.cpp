#include <bits/stdc++.h>
using namespace std;

int n;
int a[105];

int main() {
    scanf("%d", &n);
    for (int i=0; i<n; i++) {
        scanf("%d", &a[i]);
    }

    int ans = 0, j = 0;
    for (int i=1; i<n; i++) {
        if (a[i] - a[j] == i - j) {
            int now = i - j - 1;
            if (a[j] == 1 || a[i] == 1000) now++;
            ans = max(ans, now);
        } else {
            j = i;
        }
    }
    printf("%d\n", ans);
}