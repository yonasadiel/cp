#include <bits/stdc++.h>
using namespace std;

int n;
char s[100005];
int pre[100005][5];
int c[5];
int cnt[4][4];

int query_pre(int ct, int lo, int hi) {
    int ans = pre[hi][ct];
    if (lo > 0) ans -= pre[lo - 1][ct];
    return ans;
}

int query(int ct, int lo, int hi) {
    lo = (lo + 2 * n) % n;
    hi = (hi + 2 * n) % n;
    if (lo <= hi) return query_pre(ct, lo, hi);
    return query_pre(ct, 0, hi) + query_pre(ct, lo, n - 1);
}

int calc(string order, int _offset) {
    int offset[] = {_offset, 0, 0, 0, 0};
    offset[1] = offset[0] + c[order[0] - 'A'];
    offset[2] = offset[1] + c[order[1] - 'A'];
    offset[3] = offset[2] + c[order[2] - 'A'];
    int ans = 0;
    // cout << order << " with offset = " << _offset << endl;
    for (int i = 0; i < 4; i++) {
        for (int j = i + 1; j < 4; j++) {
            if (c[i] > 0 && c[j] > 0) {
                int j_ada_i = query(order[i] - 'A', offset[j], offset[(j + 1) % 4] - 1);
                int i_ada_j = query(order[j] - 'A', offset[i], offset[(i + 1) % 4] - 1);
                // cout << (char) ('A' + i) << " ada di " << (char) ('A' + j) << " sebanyak " << i_ada_j << endl;
                // cout << (char) ('A' + j) << " ada di " << (char) ('A' + i) << " sebanyak " << j_ada_i << endl;
                // ans += j_ada_i + i_ada_j;
                int tmp = min(j_ada_i, i_ada_j);
                ans += tmp;
                cnt[i][j] = i_ada_j - tmp;
                cnt[j][i] = j_ada_i - tmp;
                // printf("%d %d %d %d\n", i, j, i_ada_j, j_ada_i);
            }
        }
    }
    for(int i=0;i<4;++i){
        for(int j=0;j<4;++j){
            if(i == j || !cnt[i][j]) continue;
            for(int k=0;k<4;++k){
                if(k == i || k == j) continue;
                int tmp = min(cnt[i][j], min(cnt[j][k], cnt[k][i]));
                ans += 2*tmp;
                cnt[i][j] -= tmp;
                cnt[j][k] -= tmp;
                cnt[k][i] -= tmp;
            }
        }
    }
    for(int i=0;i<4;++i){
        for(int j=0;j<4;++j){
            if(i == j  || !cnt[i][j]) continue;
            for(int k=0;k<4;++k){
                if(k == i || k == j) continue;
                int l = 6 - i - j - k;
                int tmp = min(min(cnt[i][j], cnt[j][k]), min(cnt[k][l], cnt[l][i]));
                ans += 3*tmp;
                cnt[i][j] -= tmp;
                cnt[j][k] -= tmp;
                cnt[k][l] -= tmp;
                cnt[l][i] -= tmp;
            }
        }
    }
    for(int i=0;i<4;++i){
        for(int j=0;j<4;++j){
            if(i == j) continue;
            ans += cnt[i][j];
        }
    }
    // for(int i=0;i<4;++i){
    //     for(int j=0;j<4;++j){
    //         printf("%d ", cnt[i][j]);
    //     }
    //     puts("");
    // }
    // puts("------------------------");
    return ans;
}

void solve() {
    scanf("%s\n", s);
    n = strlen(s);

    memset(pre, 0, sizeof pre);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 4; j++) {
            pre[i][j] = i == 0 ? 0 : pre[i - 1][j];
        }
        pre[i][s[i] - 'A']++;
    }

    c[0] = pre[n - 1][0];
    c[1] = pre[n - 1][1];
    c[2] = pre[n - 1][2];
    c[3] = pre[n - 1][3];

    int ans = n;
    // printf("%s\n", s);
    for (int i = 0; i < n; i++) {
        ans = min(ans, calc("ABCD", i));
        ans = min(ans, calc("ABDC", i));
        ans = min(ans, calc("ACBD", i));
        ans = min(ans, calc("ACDB", i));
        ans = min(ans, calc("ADBC", i));
        ans = min(ans, calc("ADCB", i));
    }
    printf("%d\n", ans);
}

int main() {
    int t;
    scanf("%d\n", &t);
    while (t--) solve();
}