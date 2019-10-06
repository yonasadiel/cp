#include <bits/stdc++.h>
#define fi first
#define se second.first
#define th second.second
#define piii pair<int, pair<int, int> >
#define mp(a, b, c) make_pair(a, make_pair(b, c))
using namespace std;

int n, m, p;
int s[10];
char pet[1005][1005];
int dr[] = {1, 0, -1, 0};
int dc[] = {0, 1, 0, -1};

queue<piii> q;

bool valid(int r, int c) {
    return (0 <= r && r < n) && (0 <= c && c < m);
}

int main() {
    scanf("%d%d%d", &n, &m, &p);
    for (int i=1; i<=p; i++) {
        scanf("%d", &s[i]);
    }
    scanf("\n");
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            scanf("%c", &pet[i][j]);
        }
        scanf("\n");
    }

    for (char cc='1'; cc<='0'+p; cc++) {
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (pet[i][j] == cc) {
                    q.push(mp(1, i, j));
                    // printf("pushed %c => %d %d\n", cc, i, j);
                }
            }
        }
    }

    while (!q.empty()) {
        piii last, cur;
        queue<piii> q2;
        last = q.front(); q.pop(); q2.push(last);
        if (!q.empty()) {
            cur = q.front();
            while (pet[cur.se][cur.th] == pet[last.se][last.th]) {
                q2.push(cur);
                last = cur; q.pop();
                if (q.empty()) break;
                cur = q.front();
            }
        }

        while (!q2.empty()) {
            cur = q2.front(); q2.pop();
            // printf("processed %d,%d => %c\n", cur.se, cur.th, pet[cur.se][cur.th]);
            int turn = pet[cur.se][cur.th] - '0';

            for (int i=0; i<4; i++) {
                int nr = cur.se + dr[i];
                int nc = cur.th + dc[i];
                if (valid(nr, nc) && pet[nr][nc] == '.') {
                    pet[nr][nc] = pet[cur.se][cur.th];
                    if (cur.fi < s[turn]) {
                        q2.push(mp(cur.fi + 1, nr, nc));
                    } else {
                        q.push(mp(1, nr, nc));
                    }
                }
            }
        }
    }
    // for (int i=0; i<n; i++) {
    //     for (int j=0; j<m; j++) {
    //         printf("%c", pet[i][j]);
    //     }
    //     printf("\n");
    // }
    int cnt[15];
    memset(cnt, 0, sizeof cnt);
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if ('1' <= pet[i][j] && pet[i][j] <= '9') cnt[pet[i][j] - '0']++;
        }
    }
    for (int i=1; i<=p; i++) {
        printf("%d%c", cnt[i], (i == p? '\n' : ' '));
    }
}