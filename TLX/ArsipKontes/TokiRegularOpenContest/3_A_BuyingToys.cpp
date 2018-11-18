#include <bits/stdc++.h>
using namespace std;

int x;
int a[4];

int main() {
    scanf("%d", &x);
    scanf("%d%d%d", &a[0], &a[1], &a[2]);
    sort(a, a+3);

    int c = 0, ans=0;
    while (true) {
        if (a[c] > x) {
            break;
        }
        x -= a[c];
        c = (c+1) %3;
        ans++;
    }
    printf("%d\n", ans);
}