#include <cstdio>
#include <iostream>
using namespace std;

int convert(const string& st) {
    int ans = 0;
    int con = 1;
    for (int i=0; i<st.length(); i++) {
        if (st[i] == 'S') ans += con;
        else con <<= 1;
    }
    return ans;
}

void exec(int tc) {
    int d, ans=0; string st;
    scanf("%d",&d);
    cin >> st;

    while (convert(st) > d) {
        int gid;
        for (gid=st.length()-1; gid>0 && !(st[gid] == 'S' && st[gid-1] == 'C'); gid--) { }
        if (gid > 0) {
            st[gid] = 'C';
            st[gid-1] = 'S';
            ans++;
        } else break;
    }

    if (convert(st) <= d) {
        printf("Case #%d: %d\n", tc, ans);
    } else {
        printf("Case #%d: IMPOSSIBLE\n", tc);
    }
}

int main() {
    int t;
    scanf("%d",&t);
    for (int i=1; i<=t; i++) {
        exec(i);
    }
}