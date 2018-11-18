#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll n, m;

int main() {
    scanf("%lld", &m);

    int simpan = 0;
    ll ke = 1;
    int tambah = 0;
    n = m;
    vector<int> fak;
    for (ll i=2; i<=m; i++) {
        if (n % i == 0) {
            ke *= i;
            int cnt = 0;
            while (n % i == 0) {
                n /= i;
                cnt++;
            }
            fak.push_back(cnt);
        }
    }
    for (int i=0; i<fak.size(); i++) {
        int temp = 1;
        int cnt = 0;
        while (temp < fak[i]) {
            temp *= 2;
            cnt++;
        }
        simpan = max(simpan, cnt);
    }

    for (int i=0; i<fak.size(); i++) {
        int temp = 1;
        int cnt = 0;
        while (temp < fak[i]) {
            temp *= 2;
            cnt++;
        }
        //printf("%d %d %d %d\n", simpan, cnt, temp, fak[i]);
        if (simpan != cnt || temp != fak[i]) tambah = 1;
    }

    printf("%lld %d\n", ke, simpan + tambah);
}