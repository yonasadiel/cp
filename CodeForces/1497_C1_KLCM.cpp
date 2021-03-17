#include <vector>
#include <stack>
#include <queue>
#include <cstdio>
#include <algorithm>
using namespace std;

void solve() {
    int n, k;
    scanf("%d%d", &n, &k);
    if (n & 1) {
        printf("%d %d %d\n", n / 2, n / 2, 1);
    } else if (n % 4 == 2) {
        printf("%d %d %d\n", n / 2 - 1, n / 2 - 1, 2);
    } else {
        printf("%d %d %d\n", n / 2, n / 4, n / 4);
    }
}

int main() {
    int tc;
    scanf("%d", &tc);
    for (int i = 0; i < tc; i++) {
        solve();
    }
}