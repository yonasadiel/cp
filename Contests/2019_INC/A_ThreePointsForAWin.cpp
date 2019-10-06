#include <bits/stdc++.h>
using namespace std;

int n;
int a[100005];
int b[100005];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    for (int i = 0; i < n; i++) scanf("%d", &b[i]);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == b[i]) {
            ans += 1;
        } else if (a[i] > b[i]) {
            ans += 3;
        }
    }
    printf("%d\n", ans);

}