#include <bits/stdc++.h>
using namespace std;

int n;
int a[100005];
int b[100005];
bool sudah[100005];

int main() {
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    int ans = 0;
    int p = 0;
    memset(sudah, false, sizeof sudah);
    for (int i = 0; i < n; i++) {
        scanf("%d", &b[i]);
        while (p < n && sudah[a[p]]) p++;
        if (a[p] != b[i]) {
            ans++;
        }
        sudah[b[i]] = true;
        while (p < n && sudah[a[p]]) p++;
    }

    printf("%d\n", ans);
}
