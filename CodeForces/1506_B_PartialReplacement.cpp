#include <cstdio>
#include <cstdlib>
using namespace std;

void solve() {
    int n, k, xn;
    char* buf;
    int* x;
    scanf("%d%d", &n, &k);

    buf = (char*) malloc((n + 10) * sizeof(char));
    x = (int*) malloc((n + 10) * sizeof(int));
    xn = 0;
    
    scanf("%s", buf);
    
    int cnt = 0, m = 0;
    for (int i = 0; i < n; i++) {
        if (buf[i] == '*') {
            cnt++;
            if (xn >= 2 && i - x[xn - 2] <= k) {
                xn--;
            }
            x[xn] = i;
            xn++;
        }
    }
    printf("%d\n", xn);
}

int main() {
    int tc;
    scanf("%d", &tc);
    for (int i = 0; i < tc; i++) {
        solve();
    }
}