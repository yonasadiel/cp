#include<cstdio>
#define MOD 998244353
using namespace std;

// struct mat {
// public:
//     long long m[2][2];
// };

// mat matmul(mat a, mat b) {
//     mat c;
//     for (int i=0; i<2; i++) {
//         for (int j=0; j<2; j++) {
//             c.m[i][j] = 0;
//             for (int k=0; k<2; k++) {
//                 c.m[i][j] += (a.m[i][k] * b.m[k][j]) % MOD;
//                 c.m[i][j] %= MOD;
//             }
//         }
//     }
//     return c;
// }

// mat matexp(mat a, int p) {
//     if (p == 1) return a;
//     mat b = matexp(a, p/2);
//     mat bb = matmul(b, b);
//     if (p % 2 == 0) return bb;
//     return matmul(bb, a);
// }

// long long fastexp(long long a, long long p) {
//     if (p == 1) return a;
//     long long b = fastexp(a, p/2);
//     long long bb = (b*b) % MOD;
//     if (p % 2 == 0) return bb;
//     return  (bb * a) % MOD;
// }

// long long invmod(long long a) { return fastexp(a, MOD-2); }

long long solve() {
    long long g, w, l;
    scanf("%lld%lld%lld", &w, &g, &l);

    long long p = (l*2)%MOD;
    p += 1;
    p %= MOD;

    p *= ((w%MOD)+(MOD-(g%MOD))) % MOD;
    p %= MOD;
    return p;
}

int main() {
    int t;
    scanf("%d", &t);
    for (int i=1; i<=t; i++) {
        printf("Case #%d: %lld\n", i, solve());
    }
}
