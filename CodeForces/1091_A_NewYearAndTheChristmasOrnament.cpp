#include <bits/stdc++.h>
using namespace std;

int a, b, c;

int main() {
    scanf("%d%d%d", &a, &b, &c);
    int ans = 3 * c - 3;
    ans = min(ans, 3 * b);
    ans = min(ans, 3 * a + 3);
    printf("%d\n", ans);
}