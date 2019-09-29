#include <bits/stdc++.h>
using namespace std;

int l, r;

bool isDiff(int x) {
    int c[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    while (x > 0) {
        c[x % 10]++;
        x /= 10;
    }
    for (int i = 0; i < 10; i++) {
        if (c[i] > 1) return false;
    }
    return true;
}

int main() {
    scanf("%d%d", &l, &r);
    for (int i = l; i <= r; i++) {
        if (isDiff(i)) {
            printf("%d\n", i);
            return 0;
        }
    }
    printf("-1\n");
    return 0;
}