#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        int ans = 0;
        for (int j = 0; j < 100; j++) {
            for (int k = 0; k < 100; k++) {
                if (j <= a && j * 2 + k <= b && k * 2 <= c) {
                    ans = max(ans, j * 3 + k * 3);
                }
            }
        }
        printf("%d\n", ans);
    }
}