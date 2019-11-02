#include <bits/stdc++.h>
using namespace std;

int n;
long long x[100005];
long long y[100005];
long long z[100005];
bool sudah[100005];

long long dist(int i, int j) {
    return (
        (x[i] - x[j]) * (x[i] - x[j]) +
        (y[i] - y[j]) * (y[i] - y[j]) +
        (z[i] - z[j]) * (z[i] - z[j])
    );
}

int main() {
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%lld%lld%lld", &x[i], &y[i], &z[i]);
    }

    for (int i = 0; i < n; i++) {
        if (!sudah[i]) {
            int l = i;
            for (int j = i + 1; j < n; j++) {
                if (!sudah[j]) {
                    if (l == i || dist(j, i) < dist(l, i)) {
                        l = j;
                    }
                }
            }
            printf("%d %d\n", i + 1, l + 1);
            sudah[i] = true;
            sudah[l] = true;
        }
    }
}
