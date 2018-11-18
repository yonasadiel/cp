#include <bits/stdc++.h>
using namespace std;

int n;
int a[100005];

int main() {
    scanf("%d", &n);
    int cnt = 0;
    for (int i=0; i<n+1; i++) {
        scanf("%d", &a[i]);
        if (i > 0 && a[i] == a[i-1]) cnt++;
    }
    if (cnt > 1) {
        printf("0\n");
    } else if (cnt == 1) {
        printf("1\n");
    } else if (cnt == 0) {
        printf("%d\n", n+1);
    }
}