#include <bits/stdc++.h>
using namespace std;

double a, b, c;
double xa, xb, ya, yb;

int main() {
    scanf("%lf%lf%lf", &a, &b, &c);
    scanf("%lf%lf%lf%lf", &xa, &ya, &xb, &yb);

    double ans = fabs(xa-xb) + fabs(ya-yb);

    double xc, yc, xd, yd;

    // both x
    xc = (-b * ya - c) / a; yc = (-a * xc - c) / b;
    xd = (-b * yb - c) / a; yd = (-a * xd - c) / b;
    ans = min(
        ans,
        fabs(xa-xc) + fabs(ya-yc) + hypot((xc-xd), (yc-yd)) + fabs(xd-xb) + fabs(yd-yb)
    );

    // both y
    yc = (-a * xa - c) / b; xc = (-b * yc - c) / a;
    yd = (-a * xb - c) / b; xd = (-b * yd - c) / a;
    ans = min(
        ans,
        fabs(xa-xc) + fabs(ya-yc) + hypot((xc-xd), (yc-yd)) + fabs(xd-xb) + fabs(yd-yb)
    );

    // both x
    xc = (-b * ya - c) / a; yc = (-a * xc - c) / b;
    yd = (-a * xb - c) / b; xd = (-b * yd - c) / a;
    ans = min(
        ans,
        fabs(xa-xc) + fabs(ya-yc) + hypot((xc-xd), (yc-yd)) + fabs(xd-xb) + fabs(yd-yb)
    );

    // both y
    yc = (-a * xa - c) / b; xc = (-b * yc - c) / a;
    xd = (-b * yb - c) / a; yd = (-a * xd - c) / b;
    ans = min(
        ans,
        fabs(xa-xc) + fabs(ya-yc) + hypot((xc-xd), (yc-yd)) + fabs(xd-xb) + fabs(yd-yb)
    );

    printf("%.10lf\n", ans);
}