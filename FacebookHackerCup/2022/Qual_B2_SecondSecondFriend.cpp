#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int r, c;
char g[4000][4000];
bool o[4000][4000];

int countPossibleFriend(int i, int j) {
    int fr = 0;
    if (i-1 >= 0 && o[i-1][j]) fr++;
    if (j-1 >= 0 && o[i][j-1]) fr++;
    if (i+1 <  r && o[i+1][j]) fr++;
    if (j+1 <  c && o[i][j+1]) fr++;
    return fr;
}

int dr[] = {0, 1, 0, -1};
int dc[] = {1, 0, -1, 0};

void dfs(int rc, int cc) {
    for (int i = 0; i < 4; i++) {
        int rn = rc + dr[i];
        int cn = cc + dc[i];
        if (rn < 0 || rn >= r || cn < 0 || cn >= c) continue;
        if (!o[rn][cn]) continue;
        if (countPossibleFriend(rn, cn) < 2) {
            o[rn][cn] = false;
            dfs(rn, cn);
        }
    }
}

void solve(int tc) {
    scanf("%d%d", &r, &c);
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            scanf(" %c", &g[i][j]);
            o[i][j] = g[i][j] != '#';
        }
    }
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (g[i][j] == '#') continue;
            int fr = countPossibleFriend(i, j);
            if (fr < 2) {
                o[i][j] = false;
                dfs(i, j);
            }
        }
    }

    bool ok = true;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (g[i][j] == '^' && !o[i][j]) {
                ok = false;
            }
        }
    }


    if (!ok) {
        printf("Case #%d: Impossible\n", tc);
    } else {
        printf("Case #%d: Possible\n", tc);
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                printf("%c", o[i][j] ? '^' : g[i][j]);
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