#include <bits/stdc++.h>
using namespace std;

void solve(int tc) {
    int n, a, b, t;
    scanf("%d%d%d%d", &n, &a, &b, &t);
    printf("Kasus #%d: %d\n", tc, n+(b-a)*t);
}

int main() {
    int t;
    scanf("%d", &t);
    for (int i=1; i<=t; i++) {
        solve(i);
    }
}