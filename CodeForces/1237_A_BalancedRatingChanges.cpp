#include <bits/stdc++.h>
using namespace std;

int n;
int a[100005];
int b[100005];

int main() {
    scanf("%d", &n);

    int sumb = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        b[i] = a[i] / 2;
        sumb += b[i];
    }

    for (int i = 0; i < n; i++) {
        if (sumb != 0 && a[i] % 2 != 0) {
            if (sumb > 0) {
                if (a[i] < 0) {
                    b[i]--;
                    sumb--;
                } else {
                    //
                }
            } else {
                if (a[i] < 0) {
                    //
                } else {
                    b[i]++;
                    sumb++;
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        printf("%d\n", b[i]);
    }
}
