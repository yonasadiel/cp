#include <bits/stdc++.h>
using namespace std;

int n;
int a[100005];

int main() {
    scanf("%d", &n);
    for (int i=0; i<n; i++) {
        scanf("%d", &a[i]);
    }

    int t = 0;
    int ans = 1e9;
    for (int tt=1; tt<=102; tt++) {
        int cost = 0;
        for (int i=0; i<n; i++) {
            cost += min(min(abs(a[i] - tt), abs(a[i] - (tt + 1))), abs(a[i] - (tt - 1)));
        }
        if (cost <= ans) {
            ans = cost;
            t = tt;
        }
    }
    printf("%d %d\n", t, ans);
}