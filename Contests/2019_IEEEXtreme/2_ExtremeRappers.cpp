#include <iostream>

using namespace std;

int main() {
    long long j, k, a, b;
    scanf("%lld%lld", &k, &j);
    // a = k diambil 1, j diambil 2
    // b = k diambil 2, j diambil 1

    long long ans = 0;
    // case 1: a doang
    a = min(k, j / 2);
    b = 0LL;
    ans = max(ans, a + b);

    // case 2: b doang
    a = 0LL;
    b = min(j, k / 2);
    ans = max(ans, a + b);

    // case 3b: max di tengah, round di a
    a = (2 * j - k) / 3;
    b = min((k - a) / 2,  j - 2 * a);
    fprintf(stderr, "%lld %lld\n", a, b);
    if (a >=0 && b >= 0) ans = max(ans, a + b);

    // case 3b: max di tengah, round di b
    b = (2 * k - j) / 3;
    a = min((j - b) / 2, k - 2 * b);
    fprintf(stderr, "%lld %lld\n", a, b);
    if (a >=0 && b >= 0) ans = max(ans, a + b);

    printf("%lld\n", ans);
    return 0;
}