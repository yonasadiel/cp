// ac
#include <bits/stdc++.h>
#define ll long long
#define MOD 998244353
using namespace std;

map<string, int> to_index;
string to_str[40005];
int cnt = 0;

pair<int, ll> parent[40005];

pair<int, ll> find_parent(int x) {
    if (parent[x].first == x) return parent[x];
    pair<int, ll> px = find_parent(parent[x].first);
    parent[x] = make_pair(px.first, (px.second * parent[x].second) % MOD);
    return parent[x];
}

ll poww(ll a, ll x) {
    if (x == 0) return 1;
    if (x == 1) return a;
    ll b = poww(a, x/2);
    b *= b;
    b %= MOD;
    if (x&1) b *= a;
    b %= MOD;
    return b;
}

ll inv(ll x) {
    return poww(x, MOD-2) % MOD;
}

void uni(int a, int b, ll r) {
    pair<int, ll> pa = find_parent(a);
    pair<int, ll> pb = find_parent(b);
    if (pa.first == pb.first) return;

    parent[pa.first] = make_pair(a, inv(pa.second) % MOD);
    parent[a] = make_pair(pb.first, (r * pb.second) % MOD);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    string a, b;
    long long r;
    for (int i=0; i<40005; i++) parent[i] = make_pair(i, 1);

    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> a >> b >> r;
        if (to_index.find(a) == to_index.end()) {
            to_index[a] = cnt;
            to_str[cnt] = a;
            cnt++;
        }
        if (to_index.find(b) == to_index.end()) {
            to_index[b] = cnt;
            to_str[cnt] = b;
            cnt++;
        }
        int ia = to_index[a];
        int ib = to_index[b];
        uni(ia, ib, r);
    }
    // for (int i=0; i<cnt; i++) {
    //     cout << i << " " << to_str[i] << endl;
    // }

    cin >> q;
    for (int i=0; i<q; i++) {
        cin >> a >> b;
        if (to_index.find(a) == to_index.end() || to_index.find(b) == to_index.end()) {
            cout << -1 << endl;
            continue;
        }
        int ia = to_index[a];
        int ib = to_index[b];

        //cout << ia << " " << ib << endl;
        pair<int, ll> pa = find_parent(ia);
        pair<int, ll> pb = find_parent(ib);
        //cout << pa.second << " " << pb.second << endl;
        if (pa.first != pb.first) {
            cout << -1 << endl;
        } else {
            cout << (pa.second * inv(pb.second)) % MOD << endl;
        }
    }
}