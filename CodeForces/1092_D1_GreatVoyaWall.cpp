#include <bits/stdc++.h>
using namespace std;

int n;
int a[200005];

void solve() {
    bool bisa = false;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        a[i] %= 2;
    }

    stack<int> st;
    int ne = a[0];
    bool done = true;
    for (int i = 0; i < n || (i >= n && !done);) {
        //printf("%d %d %d\n", st.size(), ne, done);
        if (st.empty()) {
            st.push(ne);
            ne = a[++i];
            done = true;
        } else {
            int t = st.top();
            st.pop();
            if (t == ne) {
                ne = 3;
                done = false;
            } else {
                if (t == 3) {
                    ne = ne;
                    done = false;
                } else if (ne == 3) {
                    ne = t;
                    done = false;
                } else {
                    st.push(t);
                    st.push(ne);
                    ne = a[++i];
                    done = true;
                }
            }
        }
    }
    bisa = st.size() == 1;


    if (bisa) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
}

int main() {
    char s[200];
    while (scanf("%d", &n) == 1) {
        solve();
        scanf("%s", s);
    }
}
