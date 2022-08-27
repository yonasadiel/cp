#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int r, c;
char g[200][200];

void solve(int tc) {
    scanf("%d%d", &r, &c);
    int cnt = 0;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            scanf(" %c", &g[i][j]);
            if (g[i][j] == '^') cnt++;
            g[i][j] = '^';
        }
    }
    if ((r == 1 || c == 1) && cnt > 0) {
        printf("Case #%d: Impossible\n", tc);
    } else {
        printf("Case #%d: Possible\n", tc);
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                printf("%c", cnt > 0 ? '^' : '.');
            }
            printf("\n");
        }
    }

}

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) solve(i);
}