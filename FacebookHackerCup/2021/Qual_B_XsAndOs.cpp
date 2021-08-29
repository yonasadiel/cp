#include <cstdio>
using namespace std;

int n;
char m[80][80];

void solve(int tc) {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf(" %c", &m[i][j]);
        }
    }
    int ans = n + 1;
    int ansvar = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (m[i][j] != '.') continue;
            bool canrow = true;
            bool cancol = true;
            for (int k = 0; k < n; k++) {
                if (k != j && m[i][k] != 'X') cancol = false;
                if (k != i && m[k][j] != 'X') canrow = false;
            }
            if ((canrow || cancol) && ans > 1) {
                ans = 1;
                ansvar = 1;
            } else if (canrow || cancol) {
                ansvar++;
            }
        }
    }
    if (ans > 1) {
        // row
        for (int i = 0; i < n; i++) {
            int can = 0;
            for (int j = 0; j < n; j++) {
                if (m[i][j] == 'O') can = -1;
                if (m[i][j] == '.' && can != -1) can++;
            }
            if (can >= 0 && can < ans) {
                ans = can;
                ansvar = 1;
                // printf("row,i=%d,ans=%d,ansvar=%d\n", i, ans, ansvar);
            } else if (can == ans) {
                ansvar++;
                // printf("row,i=%d,ans=%d,ansvar=%d\n", i, ans, ansvar);
            }
        }
        // col
        for (int j = 0; j < n; j++) {
            int can = 0;
            for (int i = 0; i < n; i++) {
                if (m[i][j] == 'O') can = -1;
                if (m[i][j] == '.' && can != -1) can++;
            }
            if (can >= 0 && can < ans) {
                ans = can;
                ansvar = 1;
                // printf("col,j=%d,ans=%d,ansvar=%d\n", j, ans, ansvar);
            } else if (can == ans) {
                ansvar++;
                // printf("col,j=%d,ans=%d,ansvar=%d\n", j, ans, ansvar);
            }
        }
    }
    printf("Case #%d: ", tc);
    if (ans > n) {
        printf("Impossible\n");
    } else {
        printf("%d %d\n", ans, ansvar);
    }
}

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        solve(i + 1);
    }
}