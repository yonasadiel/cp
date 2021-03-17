#include <vector>
#include <stack>
#include <queue>
#include <cstdio>
#include <algorithm>
using namespace std;

void solve() {
    int n, k;
    scanf("%d%d", &n, &k);
    n -= k - 3;
    if (n & 1) {
        printf("%d %d %d", n / 2, n / 2, 1);
    } else if (n % 4 == 2) {
        printf("%d %d %d", n / 2 - 1, n / 2 - 1, 2);
    } else {
        printf("%d %d %d", n / 2, n / 4, n / 4);
    }
    for (int i = 0; i < k - 3; i++) {
        printf(" 1");
    }
    printf("\n");
}

int main() {
    int tc;
    scanf("%d", &tc);
    for (int i = 0; i < tc; i++) {
        solve();
    }
}