#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pll pair<ll,ll>
using namespace std;

ll cross(pll a, pll o, pll b) {
    return (a.fi - o.fi) * (b.se - o.se) - (a.se - o.se) * (b.fi - o.fi);
}

bool belok_kanan(pll a, pll o, pll b) {
    return cross(a,o,b) > 0;
}

bool belok_kiri(pll a, pll o, pll b) {
    return cross(a,o,b) < 0;
}

void maincase(int kasus) {
    bool bisa = true;

    int n,h;
    ll arr[55], brr[55];
    scanf("%d%d",&n,&h); n++;
    for (int i=0; i<n; i++) { scanf("%lld",&arr[i]); }
    for (int i=0; i<n; i++) { scanf("%lld",&brr[i]); brr[i] -= h; }

    pll st[55]; int nst=0;
    for (int i=0; i<n; i++) {
        pll cur = mp(i, arr[i]);

        if (nst < 2) { st[nst++] = cur; }
        else {
            while (nst >= 2 && belok_kiri(st[nst-2], st[nst-1], cur)) {
                nst--;
            }
            st[nst++] = cur;
        }
    }
    double arr_reborn[55];
    for (int i=0, sti=0; i<n; i++) {
        if (st[sti].fi == i) { arr_reborn[i] = st[sti].se; sti++; }
        else {
            arr_reborn[i] = (double) (st[sti-1].se - st[sti].se) * (i - st[sti-1].fi) / (st[sti-1].fi - st[sti].fi) + st[sti-1].se;
        }
    }


    nst=0;
    for (int i=0; i<n; i++) {
        pll cur = mp(i, brr[i]);

        if (nst < 2) { st[nst++] = cur; }
        else {
            while (nst >= 2 && belok_kanan(st[nst-2], st[nst-1], cur)) {
                nst--;
            }
            st[nst++] = cur;
        }
    }
    double brr_reborn[55];
    for (int i=0, sti=0; i<n; i++) {
        if (st[sti].fi == i) { brr_reborn[i] = st[sti].se; sti++; }
        else {
            brr_reborn[i] = (double) (st[sti-1].se - st[sti].se) * (i - st[sti-1].fi) / (st[sti-1].fi - st[sti].fi) + st[sti-1].se;
        }
    }

    for (int i=0; i<n; i++) {
        if (arr_reborn[i] > brr_reborn[i]) {
            bisa = false;
        }
    }


    if (bisa) {
        printf("Case #%d: Ya\n", kasus);
    } else {
        printf("Case #%d: Tidak\n", kasus);
    }
}

int main(){
    int cases;
    scanf("%d",&cases);
    for(int i=1; i<=cases; i++) {
        maincase(i);
    }
}
