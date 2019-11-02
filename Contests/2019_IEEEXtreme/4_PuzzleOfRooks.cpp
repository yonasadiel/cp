#include <bits/stdc++.h>
#define pii pair<int, int>
#define op pair<pii, char>
#define fi first
#define se second
#define mp make_pair
using namespace std;

int n;
pair<int, int> c[20], t[20];
vector<op> ans;
const int offset = 70;

bool first_asc(pii a, pii b) { return a.fi < b.fi; }
bool second_asc(pii a, pii b) { return a.se < b.se; }

void samain_absis() {
    sort(c, c + n, first_asc);
    sort(t, t + n, first_asc);

    for (int i = 0; i < n; i++) {
        while (c[i].fi > t[i].fi) {
            ans.push_back(mp(c[i], 'L')); c[i].fi--;
        }
    }

    for (int i = n - 1; i >= 0; i--) {
        while (c[i].fi < t[i].fi) {
            ans.push_back(mp(c[i], 'R')); c[i].fi++;
        }
    }
}

void ratain_ordinat() {
    sort(c, c + n, second_asc);

    for (int i = 0; i < n; i++) {
        int tc = i * 2 + offset;
        while (c[i].se > tc) {
            ans.push_back(mp(c[i], 'D')); c[i].se--;
        }
    }

    for (int i = n - 1; i >= 0; i--) {
        int tc = i * 2 + offset;
        while (c[i].se < tc) {
            ans.push_back(mp(c[i], 'U')); c[i].se++;
        }
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) { scanf("%d%d", &c[i].fi, &c[i].se); }
    for (int i = 0; i < n; i++) { scanf("%d%d", &t[i].fi, &t[i].se); }

    samain_absis();
    ratain_ordinat();

    int target_column[105];
    memset(target_column, 0, sizeof target_column);
    for (int i = 0; i < n; i++) {
        target_column[t[i].fi] = t[i].se;
    }

    int current_row[105], current_col[105];
    memset(current_row, -1, sizeof current_row);
    memset(current_col, -1, sizeof current_col);
    for (int i = 0; i < n; i++) {
        current_row[c[i].fi] = i;
        current_col[c[i].se] = i;
    }

    int placed = -1;
    for (int ii = 0; ii < n; ii++) {
        // cari yang harusnya di paling kiri
        int mintc = 100, mintr = 0;
        for (int jj = 0; jj < n; jj++) {
            if (t[jj].se < mintc && t[jj].se > placed) {
                mintc = t[jj].se;
                mintr = t[jj].fi;
            }
        }
        if (mintr == 0) return 3;

        int i = current_row[mintr];
        while (c[i].se > ii * 2 + offset) {
            if (c[i].se - 2 < ii * 2 + offset) return 4;
            int j = current_col[c[i].se - 2];
            // swapping
            ans.push_back(mp(c[i], 'D')); c[i].se--;
            ans.push_back(mp(c[i], 'T'));
            ans.push_back(mp(c[j], 'U')); c[j].se++;
            ans.push_back(mp(c[j], 'U')); c[j].se++;
            ans.push_back(mp(c[i], 'P'));
            ans.push_back(mp(c[i], 'D')); c[i].se--;
            current_col[c[i].se] = i;
            current_col[c[j].se] = j;
        }

        placed = mintc;
    }

    placed = 200;
    for (int ii = 0; ii < n; ii++) {
        int maxcc = 0, maxcr = 0;
        for (int jj = 0; jj < n; jj++) {
            if (c[jj].se > maxcc && c[jj].se < placed) {
                maxcc = c[jj].se;
                maxcr = c[jj].fi;
            }
        }

        int i = current_row[maxcr];
        int dest = target_column[maxcr];
        while (c[i].se < dest) {
            ans.push_back(mp(c[i], 'U')); c[i].se++;
        }

        placed = maxcc;
    }

    placed = -1;
    for (int ii = 0; ii < n; ii++) {
        int mincc = 200, mincr = 0;
        for (int jj = 0; jj < n; jj++) {
            if (c[jj].se < mincc && c[jj].se > placed) {
                mincc = c[jj].se;
                mincr = c[jj].fi;
            }
        }

        int i = current_row[mincr];
        int dest = target_column[mincr];
        while (c[i].se > dest) {
            ans.push_back(mp(c[i], 'D')); c[i].se--;
        }

        placed = mincc;
    }

    if (ans.size() > 2050) return 2;
    printf("%d\n", ans.size());
    for (int i = 0; i < ans.size(); i++) {
        printf("%d %d %c\n", ans[i].fi.fi, ans[i].fi.se, ans[i].se);
    }
    return 0;
}