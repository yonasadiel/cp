#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

char *a, *b;

void solve() {
    a = (char*) malloc(100 * sizeof(char));
    b = (char*) malloc(100 * sizeof(char));
    scanf(" %s", a);
    scanf(" %s", b);
    int na = strlen(a);
    int nb = strlen(b);
    int ans = 0;
    for (int i = 0; i < na; i++) {
        for (int j = 0; j < nb; j++) {
            int cnt = 0;
            for (int k = 0; i + k < na && j + k < nb; k++) {
                if (a[i + k] != b[j + k]) {
                    break;
                }
                cnt++;
            }
            ans = max(ans, cnt);
        }
    }
    printf("%d\n", na + nb - 2 * ans);
    free(a);
    free(b);
}

int main() {
    int tc;
    scanf("%d", &tc);
    for (int i = 0; i < tc; i++) {
        solve();
    }
}