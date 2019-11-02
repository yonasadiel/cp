#include <bits/stdc++.h>
using namespace std;

int main() {
    int n = 14000605, x;
    do {
        scanf("%d", &x);
        if (x >= 0) n -= x;
    } while (x != -1);

    if (n == 0) {
        printf("Time to attack Then-Oz!\n");
    } else if (n < 0) {
        printf("Hey Set-Range, enough travelling! This is too much!\n");
    } else {
        printf("%d possibilities more!\n", n);
    }
}