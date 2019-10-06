#include <bits/stdc++.h>
using namespace std;

struct mat {
    long long m[20][20];
};

int a, b, n, m;

mat matmul(mat a, mat b) {
    mat c;
    memset(c.m, 0, sizeof(c.m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            c.m[i][j] = 0;
            for (int k = 0; k < n; k++) {
                c.m[i][j] += a.m[i][k] * b.m[k][j];
            }
        }
    }
    return c;
}

int main() {
    scanf("%d%d", &a, &b);
    scanf("%d\n", &m);

    mat p;
    long long x;
    vector<long long> v;
    while (scanf("%lld", &x) == 1) {
        v.push_back(x);
    }
    int cc = 0;
    n = sqrt(v.size());
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            p.m[i][j] = v[cc++];
        }
    }
    mat r;
    memset(r.m, 0, sizeof(r.m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            r.m[i][j] = (i == j);
        }
    }
    for (int k = 0; k < m; k++) {
        r = matmul(r, p);
        // for (int i = 0; i < n; i++) {
        //     for (int j = 0; j < n; j++) {
        //         printf("%lld ", r.m[i][j]);
        //     }
        //     printf("\n");
        // }
        // printf("\n");
    }

    printf("%lld\n", r.m[a][b]);
}