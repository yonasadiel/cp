#include <bits/stdc++.h>
#define ll long long
using namespace std;

int ax, ay, bx, by, cx, cy;

inline int max3(int a, int b, int c) { return max(a, max(b, c)); }
inline int min3(int a, int b, int c) { return min(a, min(b, c)); }

int solve() {
    scanf("%d%d", &bx, &by);
    scanf("%d%d", &cx, &cy);

    int tans = max3(ax, bx, cx) - min3(ax, bx, cx) + max3(ay, by, cy) - min3(ay, by, cy) + 1;

    printf("%d\n", tans);

    int midx;
    if ((ax <= bx && bx <= cx) || (cx <= bx && bx <= ax)) {
        midx = bx;
    } else if ((bx <= ax && ax <= cx) || (cx <= ax && ax <= bx)) {
        midx = ax;
    } else {
        midx = cx;
    }
    for (int i = min3(ay, by, cy); i <= max3(ay, by, cy); i++) {
        printf("%d %d\n", midx, i);
    }

    for (int i = min(ax, midx); i <= max(ax, midx); i++) {
        if (i != midx) {
            printf("%d %d\n", i, ay);
        }
    }
    for (int i = min(bx, midx); i <= max(bx, midx); i++) {
        if (i != midx) {
            printf("%d %d\n", i, by);
        }
    }
    for (int i = min(cx, midx); i <= max(cx, midx); i++) {
        if (i != midx) {
            printf("%d %d\n", i, cy);
        }
    }
}

int main() {
    while (scanf("%d%d", &ax, &ay) == 2) {
        solve();
    }
}