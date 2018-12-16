#include <bits/stdc++.h>
using namespace std;

int n;
long long a[400005];
long long b[200005];

int main() {
    scanf("%d", &n);
    long long front = 0;
    long long back = 1000000000000000000;
    for (int i=0; i<n/2; i++) {
        scanf("%lld", &b[i]);
        a[i] = (i == 0 ? 0 : a[i - 1]);
        a[n-1-i] = b[i] - a[i];
        if (i > 0 && a[n-1-i] > back) {
            a[n-1-i] = back;
            a[i] = b[i] - a[n-1-i];
        }
        front = a[i];
        back = a[n-1-i];
    }
    for (int i = 0; i < n; i++) {
        printf("%lld%c", a[i], (i == n-1 ? '\n' : ' '));
    }
}
