#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define mp3(a,b,c) make_pair(a, make_pair(b,c))
#define pb push_back
#define pii pair<int,int>
#define piii pair<int, pii>
#define pll pair<ll,ll>
#define plll pair<ll, pll>
using namespace std;

int n;
ll c;
pll kota[1005];
vector<plll> edge;
int ayah[1005];

ll jarak(int a, int b) {
    return (kota[a].fi-kota[b].fi)*(kota[a].fi-kota[b].fi) + (kota[a].se-kota[b].se)*(kota[a].se-kota[b].se);
}

int cariayah(int a) {
    if (ayah[a] != a) {
        ayah[a] = cariayah(ayah[a]);
    }
    return ayah[a];
}

void maincase(int kasus) {
    scanf("%d%lld",&n,&c);
    n++;
    for (int i=0; i<n; i++) {
        scanf("%lld%lld",&kota[i].fi, &kota[i].se);
    }

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            ll jarakt = jarak(i,j);
            if (jarakt >= c) {
                edge.pb(mp3(jarakt,i,j));
            }
        }
    }

    sort(edge.begin(), edge.end());

    for (int i=0; i<n; i++) {
        ayah[i] = i;
    }

    ll ans = 0;
    int taken = 0;
    for (int ei = 0; ei < edge.size() && taken < n-1; ei++) {
        int ayaha = cariayah(edge[ei].se.fi);
        int ayahb = cariayah(edge[ei].se.se);
        if (ayaha != ayahb) {
            ayah[ayaha] = ayahb;
            ans += edge[ei].fi;
            taken++;
        }
    }
    for (int i=1; i<n; i++) { if (cariayah(i) != cariayah(0)) ans = -1LL; }
    printf("Case #%d: %lld\n", kasus, ans);

    edge.clear();
}

int main(){
    int cases;
    scanf("%d",&cases);
    for (int i = 1; i<=cases; i++) {
        maincase(i);
    }
}
