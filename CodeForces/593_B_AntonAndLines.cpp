#include <bits/stdc++.h>
using namespace std;

int n;
double k, b;
double xx1, xx2;
pair<double, int> yy1[100005];
pair<double, int> yy2[100005];

int main() {
    scanf("%d", &n);
    scanf("%lf%lf", &xx1, &xx2);
    xx1 += 0.00000001;
    xx2 -= 0.00000001;
    for (int i=0; i<n; i++) {
        scanf("%lf%lf", &k, &b);
        yy1[i].first = k * xx1 + b; yy1[i].second = i;
        yy2[i].first = k * xx2 + b; yy2[i].second = i;
    }

    sort(yy1, yy1+n);
    sort(yy2, yy2+n);

    for (int i=0; i<n; i++) {
        if (yy1[i].second != yy2[i].second) {
            printf("Yes\n");
            return 0;
        }
    }
    printf("No\n");
}