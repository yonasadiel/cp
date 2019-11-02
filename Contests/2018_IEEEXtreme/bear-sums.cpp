#include <bits/stdc++.h>
using namespace std;

int s, e;
int x;
map<int, int> m;

void solve() {
    m.clear();
    bool found = false;
    scanf("%d%d", &s, &e);
    for (int i=0; i<e; i++) {
        scanf("%d", &x);

        if (!found) {
            if (m.find(x) == m.end())
                m[x] = 0;
            m[x]++;

            if (m.find(s-x) != m.end()) {
                if (s-x == x) {
                    if (m[x] <= 1) continue;
                }
                printf("%d %d\n", min(x, s-x), max(x, s-x));
                found = true;
            }
        }
    }
    if (!found)
        printf("!OK\n");
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) solve();
}