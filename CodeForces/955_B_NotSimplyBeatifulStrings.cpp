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

int main() {
  string s;
  cin >> s;
  int al[26];
  memset(al, 0, sizeof al);
  for (int i=0; i<s.length(); i++) {
    al[s[i] - 'a']++;
  }
  vector<int> cnt;
  for (int i=0; i<26; i++) {
    if (al[i] > 0) cnt.pb(al[i]);
  }

  if (cnt.size() == 3 && s.length() == 3) {
    printf("No\n");
  } else if (cnt.size() > 4) {
    printf("No\n");
  } else if (cnt.size() >= 3) {
    printf("Yes\n");
  } else if (cnt.size() == 2 && cnt[0] > 1 && cnt[1] > 1) {
    printf("Yes\n");
  } else {
    printf("No\n");
  }
}
