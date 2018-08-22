#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define mp make_pair
#define pii pair<int, int>
using namespace std;

const int dr[] = {0, 1, -1, 0, 1, 1, -1, -1};
const int dc[] = {1, 0, 0, -1, 1, -1, 1, -1};

int r, c, k, qs;
char cc;
int grid[1005][1005];
queue<pii> q;

bool in_bound(pii _p) {
    return _p.fi >= 0 && _p.fi < r && _p.se >= 0 && _p.se < c;
}

int main() {
    scanf("%d%d%d%d\n", &r, &c, &k, &qs);
    for (int i=0; i<r; i++) {
        for (int j=0; j<c; j++) {
            scanf("%c", &cc);
            if (cc == 'X') {
                grid[i][j] = 0;
                q.push(mp(i, j));
            }
            else grid[i][j] = -1;
        }
        scanf("\n");
    }

    while (!q.empty()) {
        pii cur = q.front(); q.pop();

        for (int i=0; i<4; i++) {
            pii nex = mp(cur.fi+dr[i], cur.se+dc[i]);
            if (in_bound(nex) && grid[nex.fi][nex.se] == -1) {
                grid[nex.fi][nex.se] = grid[cur.fi][cur.se] + 1;
                q.push(nex);
            }
        }
    }

    int x, y;
    for (int i=0; i<qs; i++) {
        scanf("%d%d", &x, &y);
        printf("%d\n", grid[x-1][y-1]);
    }


}