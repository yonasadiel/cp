#include <bits/stdc++.h>
using namespace std;

int a, b, c, x;

int main() {
    scanf("%d%d%d", &a, &b, &c);

    for (int i=2; i<=100; i++) {
        if (i % a != 0 && i % b != 0 && i % c != 0) {
            x = i;
        }
    }
    printf("%d\n", x);
}