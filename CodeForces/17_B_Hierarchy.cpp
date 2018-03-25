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
#define DEBUG if (debug)
using namespace std;

const bool debug = true;

void dump(int x) { fprintf(stderr, "%d", x); }
void dump(char x) { fprintf(stderr, "%c", x); }
void dump(char* x) { fprintf(stderr, "%s", x); }
void dump(ll x) { fprintf(stderr, "%I64d", x); }
void dump(float x) { fprintf(stderr, "%.5f", x); }
void dump(double x) { fprintf(stderr, "%.5lf", x); }
void dump(string x) { cerr << x; }
template<class T> void dump(T* x, int n) { dump('['); for (int i=0; i<n; i++) { if (i>0) dump(','); dump(x[i]); } dump(']'); }
template<class T> void dump(vector<T> x) { dump('<'); for (int i=0; i<x.size(); i++) { if (i>0) dump(','); dump(x[i]); } dump('>'); }
template<class T1, class T2> void dump(pair<T1, T2> x) { dump('('); dump(x.fi); dump(','); dump(x.se); dump(')'); }

void dumpln() { fprintf(stderr, "\n"); }
template<class T> void dumpln(T* x, int n) { dump(x, n); dump('\n'); }
template<class T> void dumpln(T x) { dump(x); dumpln(); }

int n,m;
int a,b,c;
int arr[1005];
int q[1005];
int max_i;
#define INF 10000000

int main() {
  scanf("%d",&n);
  max_i = 0;
  for (int i=0; i<n; i++) { arr[i] = INF; }
  for (int i=0; i<n; i++) {
    scanf("%d",&q[i]);
    if (q[i] > q[max_i]) { max_i = i; }
  }
  scanf("%d",&m);
  for (int i=0; i<m; i++) {
    scanf("%d%d%d",&a,&b,&c); b--;
    arr[b] = min(c, arr[b]);
  }

  int sum =0;
  for (int i=0; i<n; i++) {
    if (arr[i] == INF && i != max_i) {
      printf("-1\n");
      return 0;
    } else if (arr[i] != INF) {
      sum += arr[i];
    }
  }
  printf("%d\n", sum);
}
