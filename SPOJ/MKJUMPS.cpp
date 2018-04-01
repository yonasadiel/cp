#include <cstdio>
#include <algorithm>
using namespace std;

int n;
int dist[20][20];
int dr[] = {2, 2, -2, -2, 1, 1, -1, -1};
int dc[] = {1, -1, 1, -1, 2, -2, 2, -2};
int ans;

bool valid(int rn, int cn) {
    return
        (rn >=0 && cn >= 0) &&
        (rn < 10 && cn < 10) &&
        dist[rn][cn] == -1;
}

void bt(int rn, int cn) {
    bool buntu = true;
    for (int i=0; i<8; i++) {
        int rt = rn + dr[i];
        int ct = cn + dc[i];
        if (valid(rt, ct)) {
            buntu = false;
            dist[rt][ct] = dist[rn][cn] + 1;
            //if (rt > 4) { printf("(%d,%d) to (%d,%d)\n", rn, cn, rt, ct); }
            bt(rt, ct);
            dist[rt][ct] = -1;
        }
    }

    if (buntu) {
        int count = 0;
        for (int i=0; i<10; i++) {
            for (int j=0; j<10; j++) {
                if (dist[i][j] == -1) {
                    count++;
                }
            }
        }
        ans = min(ans, count);
    }
}

void exec(int tc) {
    for (int i=0; i<20; i++)
        for (int j=0; j<20; j++)
            dist[i][j] = -2;

    int ca, cb;
    for (int ri=0; ri<n; ri++) {
        scanf("%d%d", &ca, &cb);
        for (int ci=ca; ci<ca+cb; ci++) {
            dist[ri][ci] = -1;
        }
    }

    dist[0][0] = 0;
    ans = 1000;
    bt(0,0);
    if (ans == 1)
        printf("Case %d, %d square can not be reached.\n", tc, ans);
    else 
        printf("Case %d, %d squares can not be reached.\n", tc, ans);
}

int main() {
    int tc = 1;
    scanf("%d",&n);
    while (n > 0) {
        exec(tc);
        tc++;
        scanf("%d",&n);
    }
}