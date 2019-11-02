#include <bits/stdc++.h>
using namespace std;

#define DEBUG if(false)

int n, c, r;
int re[105][2];
int k[2005];
long long h[2005];
vector<int> anti[1005];

void solve() {
    scanf("%d%d%d", &n, &c, &r);
    for (int i = 0; i < 1000; i++) {
        anti[i].clear();
    }
    for (int i = 0; i < r; i++) {
        scanf("%d %d", &re[i][0], &re[i][1]);
        anti[re[i][0]].push_back(re[i][1]);
        anti[re[i][1]].push_back(re[i][0]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d %lld", &k[i], &h[i]);
        k[n+i] = k[i];
        h[n+i] = h[i];
    }

    int cnt[1005];
    memset(cnt, 0, sizeof cnt);
    int head = 0, tail = 0;
    cnt[k[0]]++;
    long long best_sum = 0;
    int best_cnt, best_type;
    long long run_sum = h[0];
    int run_cnt = 1;
    int run_type = 1;
    while (true) { // O(N)
        int ne = head + 1;
        if (ne == 2 * n) break;
        bool bisa;
        do {
            bisa = true;
            for (int antine : anti[k[ne]]) { // O(R)
                if (cnt[antine] > 0) {
                    bisa = false;
                }
            }
            if (ne - tail >= n) bisa = false;
            if (!bisa) {
                DEBUG printf("majuin tail %d -> %d\n", tail, (tail + 1) % n);
                run_sum -= h[tail];
                run_cnt--;
                run_type = (cnt[k[tail]] == 1 ? run_type - 1 : run_type);
                cnt[k[tail]]--;
                tail++;
                DEBUG printf("run_sum = %d, run_cnt=%d, run_type=%d\n", run_sum, run_cnt, run_type);
            }
        } while(!bisa);
        DEBUG printf("majuin head %d -> %d\n", head, ne);
        run_sum += h[ne];
        run_cnt++;
        run_type = (cnt[k[ne]] == 0 ? run_type + 1 : run_type);
        cnt[k[ne]]++;
        head = ne;
        DEBUG printf("run_sum = %d, run_cnt=%d, run_type=%d\n", run_sum, run_cnt, run_type);

        if ((run_type > best_type) ||
            (run_type == best_type && run_sum / run_cnt > best_sum / best_cnt)
            // || (run_type == best_type && run_sum == best_sum && run_cnt < best_cnt)
            ) {
            best_sum = run_sum;
            best_cnt = run_cnt;
            best_type = run_type;
        }
    }
    printf("%lld %d\n", best_sum / (long long) best_cnt, best_type);
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) solve();
}