#include <bits/stdc++.h>
#define mp make_pair
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;

int dr[] = {0, 1, 0, -1};
int dc[] = {1, 0, -1, 0};

int r, c;
char grid[105][105];
int rgrid[305][305];

int bfs(int sr, int sc, int fill) {
    queue<pii> q;
    int count = 1;

    q.push(mp(sr, sc));
    rgrid[sr][sc] = fill;

    while (!q.empty()) {
        pii cu = q.front(); q.pop();

        int cr = cu.fi, cc = cu.se;
        for (int i=0; i<4; i++) {
            int nr = cr + dr[i], nc = cc + dc[i];
            if (nr >= 0 && nr < r*3 && nc >= 0 && nc < c*3 &&
                rgrid[nr][nc] == 0) {
                rgrid[nr][nc] = fill;
                q.push(mp(nr, nc));
                count++;
            }
        }
    }
    return count;
}

int main() {
    int tc = 0;
    while (true) {
        tc++;
        scanf("%d%d", &c, &r);
        if (r == 0 && c == 0) break;
        scanf("\n");
        for (int i=0; i<r; i++) {
            for (int j=0; j<c; j++) {
                scanf("%c", &grid[i][j]);
            }
            scanf("\n");
        }

        for (int i=0; i<r; i++) {
            for (int j=0; j<c; j++) {
                rgrid[i*3 + 0][j*3 + 0] = (grid[i][j] == '\\'? -1 : 0);
                rgrid[i*3 + 0][j*3 + 1] = 0;
                rgrid[i*3 + 0][j*3 + 2] = (grid[i][j] == '/'? -1 : 0);
                rgrid[i*3 + 1][j*3 + 0] = 0;
                rgrid[i*3 + 1][j*3 + 1] = -1;
                rgrid[i*3 + 1][j*3 + 2] = 0;
                rgrid[i*3 + 2][j*3 + 0] = (grid[i][j] == '/'? -1 : 0);
                rgrid[i*3 + 2][j*3 + 1] = 0;
                rgrid[i*3 + 2][j*3 + 2] = (grid[i][j] == '\\'? -1 : 0);
            }
        }

        for (int i=0; i<r*3; i++) {
            if (rgrid[i][0] == 0) bfs(i, 0, -2);
            if (rgrid[i][c * 3 - 1] == 0) bfs(i, c * 3 - 1, -2);
        }

        for (int i=0; i<c*3; i++) {
            if (rgrid[0][i] == 0) bfs(0, i, -2);
            if (rgrid[r * 3 - 1][i] == 0) bfs(r * 3 - 1, i, -2);
        }

        // for (int i=0; i<r*3; i++) {
        //     for (int j=0; j<c*3; j++) {
        //         printf("%c", (rgrid[i][j] == 0? ' ' : (rgrid[i][j] == -1? '#' : '.')));
        //     }
        //     printf("\n");
        // }

        int cnt = 0;
        int maks = 0;
        for (int i=0; i<r*3; i++) {
            for (int j=0; j<c*3; j++) {
                if (rgrid[i][j] == 0) {
                    int res = bfs(i, j, 1);
                    // printf("%d %d %d\n", i, j, res);
                    maks = max(maks, res);
                    cnt++;
                }
            }
        }

        printf("Maze #%d:\n", tc);
        if (cnt == 0)
            printf("There are no cycles.\n");
        else
            printf("%d Cycles; the longest has length %d.\n", cnt, maks / 3);
        printf("\n");
    }
}