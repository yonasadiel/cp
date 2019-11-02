#include <bits/stdc++.h>
using namespace std;

int t, a, b;

int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &a, &b);
        if (__gcd(a, b) == 1) {
            printf("Finite\n");
        } else {
            printf("Infinite\n");
        }
    }
}