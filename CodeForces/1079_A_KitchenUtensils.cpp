#include <bits/stdc++.h>
using namespace std;

int n, k, x;
int a[105];

int main() {
    memset(a, 0, sizeof a);
    scanf("%d%d", &n, &k);
    for (int i=0; i<n; i++) {
        scanf("%d", &x);
        a[x]++;
    }
    int cnt = 0, all = 0;
    for (int i=1; i<=100; i++) {
        if (a[i] > 0) {
            cnt = max(cnt, (a[i]+k-1)/k);
            all++;
        }
    }
    printf("%d\n", cnt*k*all-n);
}