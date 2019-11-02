#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll b;
int p;
int s, l;
int r1, r2, c1, c2;
int k;
int cp;
ll pos[12];

unordered_map<ll, ll> tp;
set<ll> visit;

ll to_index(int c, int r) {
    if (c == 0 && r == 1) return 0;
    if (c == 0 && r == b) return b * b + 1;

    if (r & 1) return (r - 1) * b + c;
    else return (r - 1) * b + b + 1 - c;
}

int to_row(ll x) {
    if (x == 0) return 1;
    if (x == b * b + 1) return b;
    return (x - 1) / b + 1;
}

int to_col(ll x) {
    if (x == 0) return 0;
    if (x == b * b + 1) return 0;

    int maybe = x % b;
    if (maybe == 0) maybe = b;
    if (to_row(x) & 1) {
        return maybe;
    } else {
        return b + 1 - maybe;
    }
}

void change_player() {
    cp++;
    if (cp > p) cp = 1;
}

ll travel(ll pos) {
    if (tp.find(pos) != tp.end()) {
        if (visit.find(pos) == visit.end()) {
            return tp[pos];
        }
        visit.insert(pos);
        tp[pos] = travel(tp[pos]);
        return tp[pos];
    } else {
        return pos;
    }
}

int main() {
    scanf("%lld", &b);
    scanf("%d", &p);
    scanf("%d", &s);
    for (int i=0; i<s; i++) {
        scanf("%d%d%d%d", &c1, &r1, &c2, &r2);
        ll from = to_index(c1, r1);
        ll to = to_index(c2, r2);
        tp[from] = to;
    }
    scanf("%d", &l);
    for (int i=0; i<l; i++) {
        scanf("%d%d%d%d", &c1, &r1, &c2, &r2);
        ll from = to_index(c1, r1);
        ll to = to_index(c2, r2);
        tp[from] = to;
    }

    for (pair<ll, ll> x : tp) {
        if (visit.find(x.first) == visit.end()) {
            visit.insert(x.first);
            tp[x.first] = travel(tp[x.first]);
        }
    }

    for(int i=1; i<=p; i++) {
        pos[i] = 0;
    }

    scanf("%d", &k);
    cp = 0;
    int d1, d2;
    for (int i=0; i<k; i++) {
        change_player();
        scanf("%d%d", &d1, &d2);
        ll &cpos = pos[cp];
        if (cpos < b * b + 1) {
            cpos = cpos + d1 + d2;
            if (cpos > b * b + 1) cpos = b * b + 1;

            while (tp.find(cpos) != tp.end()) {
                cpos = tp[cpos];
            }
        }

        //printf("%d now in %d %d\n", cp, to_col(cpos), to_row(cpos));
    }

    for (int i=1; i<=p; i++) {
        printf("%d ", i);
        if (pos[i] == b * b + 1) {
            printf("winner\n");
        } else if (pos[i] == 0) {
            printf("0 1\n");
        } else {
            printf("%d %d\n", to_col(pos[i]), to_row(pos[i]));
        }
    }
}