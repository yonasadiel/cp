#include <vector>
#include <stack>
#include <queue>
#include <cstdio>
#include <algorithm>
using namespace std;

int arr[100005];

void solve() {
    int n, m, x;
    scanf("%d%d", &n, &m);
    for (int i = 0; i <= m; i++) {
        arr[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        arr[x % m]++;
    }
    int ans = 0;
    for (int i = 0, j = m; i <= j; i++, j--) {
        if (i == j || i == 0) {
            // ans += arr[i] % 2;
            // printf("debug %d: %d\n", i, 1);
        } else {
            int k = min(arr[i], arr[j]);
            int l = max(0, arr[i] + arr[j] - (2 * k + 1));
            // printf("debug %d: %d\n", i, l+1);
            ans += l;
        }
        if (arr[i] + arr[j] > 0) {
            ans++;
        }
    }
    printf("%d\n", ans);
}

int main() {
    int tc;
    scanf("%d", &tc);
    for (int i = 0; i < tc; i++) {
        solve();
    }
}