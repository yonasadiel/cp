#include <bits/stdc++.h>
#define ll long long
using namespace std;

int grundy[100];

void first() { printf("Ardy\n"); }
void second() { printf("Reyhan\n"); }

bool check(ll x, ll y) {
    if (x == 1) {
        return true;
    } else if (x + 1 <= y) {
        return (x % 2 == 1);
    } else {
        ll mod = ((y-1) / 2) * 4 + 3 + ((y-1) % 2);
        ll up = ((y-1) / 2) * 2;
        ll k = x % mod;
        if (k % 2 == 0 && k <= up) {
            return false;
        } else {
            return true;
        }
    }
}

int main() {
    // grundy[0] = 0;
    // printf("  "); for (int i=1; i<=30; i++) { printf("%2d ", i); } printf("\n");
    // for (int y=1; y<=30; y++) {
    //     // printf("%2d", y);
    //     for (int x=1; x<=30; x++) {
    //         int g = 0;
    //         int a[] = {-1, -1, -1};
    //         if (x-1 >= 0) a[0] = grundy[x-1];
    //         if (x-y >= 0) a[1] = grundy[x-y];
    //         if (x-y-1 >= 0) a[2] = grundy[x-y-1];
    //         sort(a, a+3);
    //         for (int j=0; j<3; j++) if (g == a[j]) g++;
    //         grundy[x] = g;
    //         // printf(" %c ", (g == 0 ? 'K' : ' '));
    //         if (g != 0 ^ check(x, y)) {
    //             printf("%d, %d\n", x, y);
    //         }
    //     }
    //     printf("\n");
    // }

    int t;
    scanf("%d", &t);
    while (t--) {
        ll x, y;
        scanf("%lld%lld", &x, &y);
        if (check(x, y)) { first(); } else { second(); }
    }
}