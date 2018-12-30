#include <bits/stdc++.h>
using namespace std;

int n;
string a, b;

int main() {
    cin >> n;
    cin >> a >> b;
    int pa[3], pb[3];
    memset(pa, 0, sizeof pa);
    memset(pb, 0, sizeof pb);
    for (char x : a) {
        if (x == 'G') pa[0]++;
        if (x == 'B') pa[1]++;
        if (x == 'K') pa[2]++;
    }
    for (char x : b) {
        if (x == 'G') pb[0]++;
        if (x == 'B') pb[1]++;
        if (x == 'K') pb[2]++;
    }

    printf("%d\n", min(pb[0], pa[1]) + min(pb[1], pa[2]) + min(pb[2], pa[0]));
}