#include <bits/stdc++.h>
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;

int r, c;
char grid[90][90];
int visited[90][90];
int dist[90][90];

int dr[] = {1, 0, -1, 0};
int dc[] = {0, 1, 0, -1};
string dir = "DRUL";

string bfs(pii from) {
    queue<pii> q;
    memset(visited, -1, sizeof visited);
    memset(dist, -1, sizeof dist);
    visited[from.fi][from.se] = 0;
    dist[from.fi][from.se] = 0;

    for (int i=0; i<4; i++) {
        pii next = make_pair(from.fi + dr[i], from.se + dc[i]);
        if (next.fi >= 0 && next.fi < r &&
            next.se >= 0 && next.se < c &&
            grid[next.fi][next.se] != '#') {
            visited[next.fi][next.se] = i;
            dist[next.fi][next.se] = 1;
            q.push(next);
        }
    }

    while (!q.empty()) {
        pii cur = q.front(); q.pop();

        for (int i=0; i<4; i++) {
            pii next = make_pair(cur.fi + dr[i], cur.se + dc[i]);
            if (next.fi >= 0 && next.fi < r &&
                next.se >= 0 && next.se < c &&
                visited[next.fi][next.se] == -1 &&
                grid[next.fi][next.se] != '#') {
                visited[next.fi][next.se] = visited[cur.fi][cur.se];
                dist[next.fi][next.se] = dist[cur.fi][cur.se] + 1;
                q.push(next);
            }
        }
    }

    int mindist = 999;
    int poll[4];
    int go = 0;
    vector<int> poss;
    for (int i=0; i<r; i++) {
        for (int j=0; j<c; j++) {
            if (grid[i][j] == '@') {
                if (dist[i][j] < mindist) {
                    mindist = dist[i][j];
                    poss.clear();
                    poss.push_back(visited[i][j]);
                } else if (dist[i][j] == mindist) {
                    poss.push_back(visited[i][j]);
                }
            }
        }
    }
    go = poss[rand() % poss.size()];
    //cout << go << endl;
    string anss;
    anss = dir[go];
    return anss;
}

int main() {
    srand(94097);
    pii player, judge;

    scanf("%d%d", &r, &c);
    r = 2 * r + 1; c = 2 * c + 1;

    for (int i=0; i<r; i++) {
        scanf("\n");
        for (int j=0; j<c; j++) {
            scanf("%c", &grid[i][j]);
            if (grid[i][j] == '1') { player.fi = i; player.se = j; }
            else if (grid[i][j] == '2') { judge.fi = i; judge.se = j; }
        }
    }

    do {
        string ans = bfs(player);
        if (ans == "U") { player.fi -= 2; }
        if (ans == "D") { player.fi += 2; }
        if (ans == "L") { player.se -= 2; }
        if (ans == "R") { player.se += 2; }
        if (grid[player.fi][player.se] == '@') { grid[player.fi][player.se] = '.'; }
        cout << ans << endl;

        string judge_move;
        cin >> judge_move;
        if (judge_move.length() == 2) break;
        if (judge_move == "U") { judge.fi -= 2; }
        if (judge_move == "D") { judge.fi += 2; }
        if (judge_move == "L") { judge.se -= 2; }
        if (judge_move == "R") { judge.se += 2; }
        if (grid[judge.fi][judge.se] == '@') { grid[judge.fi][judge.se] = '.'; }
    } while (1);

    return 0;
}