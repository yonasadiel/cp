#include <bits/stdc++.h>
using namespace std;

int n, p, t, v, d;
int s0[2005];
int s1[2005];
int h[2005];

int main() {
    scanf("%d%d%d%d%d",&n, &p, &t, &v, &d);
    for (int i=0; i<n; i++) {
        scanf("%d", &s0[i]);
        s1[i] = s0[i] + p;
    }
    for (int i=0; i<n; i++) {
        scanf("%d", &h[i]);
        if (h[i] > t) h[i] = t;
    }

    for (int i=1; i<n; i++) {
        int j=i-1;
        while (j-1 >= 0 && s1[j-1] > s0[i]) { j--; }
        for (int k=j; k<i; k++) {
            if (h[k] <= h[i] && s0[i] < s1[k]) {
                s0[i] = s1[k];
            }
        }
        for (int k=j; k<i; k++) {
            if (h[k] > h[i] && s1[k] > s0[i]) {
                s1[k] = s0[i];
            }
        }
    }
    double ans = 0;
    for (int i=0; i<n; i++) {
        if (s1[i] > s0[i]) {
            double ti = (s1[i] - s0[i]);
            ti /= v;
            double harga = d * (t - h[i]) * ti;
            //printf("%d s/d %d tinggi %d harga %.3lf\n", s0[i], s1[i], h[i], harga);
            ans += harga;
        }
    }
    printf("%.8lf\n", ans);
}