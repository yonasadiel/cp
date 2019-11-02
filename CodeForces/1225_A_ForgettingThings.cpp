#include <bits/stdc++.h>
using namespace std;

int main() {
    int da, db;
    scanf("%d%d", &da, &db);
    if (da == db - 1) {
        printf("%d9 %d0\n", da, db);
    } else if (da == db) {
        printf("%d12 %d13\n", da, db);
    } else if (da == 9 && db == 1) {
        printf("99 100\n");
    } else {
        printf("-1\n");
    }
}