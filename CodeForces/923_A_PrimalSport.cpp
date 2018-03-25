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

const bool debug = true;

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

#define MAXN 1000000
int f[MAXN+5];
int x2;

void generate() {
    for (int i=0; i<=MAXN; i++) { f[i] = i; }
    for (int i=2; i<=MAXN; i++) {
        if (f[i] == i) {
            f[i] = 1;
            for (int j=2*i; j<=MAXN; j+=i) {
                f[j]=i;
            }
        }
    }
}

int main() {
    generate();
    scanf("%d", &x2);
    set<int> s;
    int ans = x2;
    for (int i=x2-f[x2]+1; i<=x2; i++) {
        s.insert(i);
    }
    for (set<int>::iterator it=s.begin(); it != s.end(); it++) {
        ans = min(ans, *it-f[*it]+1);
    }
    printf("%d\n", ans);
}
