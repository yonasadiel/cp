#include <bits/stdc++.h>
using namespace std;

int aa, ab, ac, ad;
int DEBUG = 0;

int setup(int& r, int& c, int& q) {
    if (DEBUG) {
        r = c = q = 10;
        return 0;
    }
    scanf("%d%d%d", &r, &c, &q);
    return 1;
}

int tanya(int x, int y) {
    if (DEBUG) {
        return min(
            (abs(aa - x) + abs(ab - y)),
            (abs(ac - x) + abs(ad - y))
        );
    }

    int ans;
    printf("? %d %d\n", x, y); fflush(stdout);
    scanf("%d", &ans);
    return ans;
}

int jawab(int ba, int bb, int bc, int bd) {
    if (DEBUG) {
        return (
            (aa == ba && ab == bb && ac == bc && ad == bd) ||
            (aa == bc && ab == bd && ac == ba && ad == bb)
        );
    }
    printf("! %d %d %d %d\n", ba, bb, bc, bd); fflush(stdout);
    return 0;
}

int solve() {
    int r, c, q, x;
    int a[6];
    int ra[6], ca[6];

    setup(r, c, q);

    a[0] = tanya(1, 1);
    a[1] = tanya(r, 1);
    a[2] = tanya(1, c);
    a[3] = tanya(r, c);

    int dx;
    dx = ((1 + a[0]) - (r - a[1])) / 2;
    ra[0] = 1 + a[0] - dx;
    ca[0] = 1 + dx;
    // printf("%d => %d %d\n", dx, ra[0], ca[0]);

    dx = ((1 + a[0]) - (c - a[2])) / 2;
    ra[1] = 1 + dx;
    ca[1] = 1 + a[0] - dx;
    // printf("%d => %d %d\n", dx, ra[1], ca[1]);

    dx = ((1 + a[1]) - (c - a[3])) / 2;
    ra[2] = r - dx;
    ca[2] = 1 + a[1] - dx;
    // printf("%d => %d %d\n", dx, ra[2], ca[2]);

    dx = ((1 + a[2]) - (r - a[3])) / 2;
    ra[3] = 1 + a[2] - dx;
    ca[3] = c - dx;
    // printf("%d => %d %d\n", dx, ra[3], ca[3]);

    if (1 <= ra[0] && ra[0] <= r && 1 <= ca[0] && ca[0] <= c && ((1 + a[2]) - (r - a[3])) % 2 == 0) {
        a[4] = tanya(ra[0], ca[0]);

        if (a[4] == 0) {
            assert(((1 + a[0]) - (r - a[1])) % 2 == 0);
            assert(((1 + a[2]) - (r - a[3])) % 2 == 0);
            return jawab(ra[0], ca[0], ra[3], ca[3]);
        } else {
            assert(((1 + a[0]) - (c - a[2])) % 2 == 0);
            assert(((1 + a[1]) - (c - a[3])) % 2 == 0);
            return jawab(ra[1], ca[1], ra[2], ca[2]);
        }
    } else {
        assert(((1 + a[0]) - (c - a[2])) % 2 == 0);
        assert(((1 + a[1]) - (c - a[3])) % 2 == 0);
        return jawab(ra[1], ca[1], ra[2], ca[2]);
    }
}

int main() {
    DEBUG = 1;
    for (aa = 1; aa <= 10; aa++) {
        for (ab = 1; ab <= 10; ab++) {
            for (ac = 1; ac <= 10; ac++) {
                for (ad = 1; ad <= 10; ad++) {
                    if (!solve()) {
                        printf("=> (%d, %d) (%d, %d)\n", aa, ab, ac, ad);
                        assert(false);
                    }
                }
            }
        }
    }
    DEBUG = 0;
    solve();
}
