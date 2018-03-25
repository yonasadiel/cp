#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <stack>
#include <map>
#include <set>
#define ll long long
#define pb push_back
#define fi first
#define se second
#define mp make_pair
#define vi vector<int>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pdd pair<double,double>
#define DEBUG if (debug)
using namespace std;

const bool debug = false;

void dump(int x) { fprintf(stderr, "%d", x); }
void dump(char x) { fprintf(stderr, "%c", x); }
void dump(char* x) { fprintf(stderr, "%s", x); }
//void dump(ll x) { fprintf(stderr, "%I64d", x); }
void dump(float x) { fprintf(stderr, "%.5f", x); }
void dump(double x) { fprintf(stderr, "%.5lf", x); }
void dump(string x) { cerr << x; }
template<class T> void dump(T* x, int n) { dump('['); for (int i=0; i<n; i++) { if (i>0) dump(','); dump(x[i]); } dump(']'); }
template<class T> void dump(vector<T> x) { dump('<'); for (int i=0; i<x.size(); i++) { if (i>0) dump(','); dump(x[i]); } dump('>'); }
template<class T1, class T2> void dump(pair<T1, T2> x) { dump('('); dump(x.fi); dump(','); dump(x.se); dump(')'); }

void dumpln() { fprintf(stderr, "\n"); }
template<class T> void dumpln(T* x, int n) { dump(x, n); dump('\n'); }
template<class T> void dumpln(T x) { dump(x); dumpln(); }

int n;
ll x;
ll arr[100005];
ll brr[100005];
vector<pll> crr[100005];

int main() {
    scanf("%d",&n);
    for (int i=0; i<n; i++) {
        scanf("%I64d",&arr[i]);
    }
    for (int i=0; i<n; i++) {
        scanf("%I64d",&x);
        brr[i] = (i==0)? x : x + brr[i-1];
    }

    for (int i=0; i<n; i++) {
        ll po = (i==0)? 0 : brr[i-1];
        int idx = lower_bound(brr, brr+n, arr[i] + po) - brr;
        ll beforeday = (idx==0)? 0 : brr[idx-1];
        crr[idx].pb(mp(idx, arr[i] + po - beforeday));
    }

    int cnt = 0;
    for (int i=0; i<n; i++) {
        ll thisday = (i==0)? brr[i] : brr[i] - brr[i-1];
        cnt++;
        ll sum = cnt * thisday;
        for (int j=0; j<crr[i].size(); j++) {
            sum -= thisday;
            sum += crr[i][j].se;
            cnt--;
        }
        printf("%I64d%c", sum, (i == n-1)? '\n' : ' ');
    }
    printf("\n");
}
