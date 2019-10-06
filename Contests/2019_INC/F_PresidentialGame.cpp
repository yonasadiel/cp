#include <bits/stdc++.h>
using namespace std;

int n, k;
int a[200005];

int main() {
    scanf("%d%d", &n, &k);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        sum += a[i];
    }
    if (sum & 1) {
        printf("John\n");
    } else {
        printf("Preston\n");
    }

}