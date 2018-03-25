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

bool debug = false;

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

int n;
string nama[105];
string snama[105];
vi to[50];
int count_parent[50];
bool bisa = true;
string ans;

void topo(int cur) {
  for (int i=0; i<to[cur].size(); i++) {
    count_parent[to[cur][i]]--;
    if (count_parent[to[cur][i]] == 0) {
      ans += (char) (to[cur][i]+'a');
      topo(to[cur][i]);
    }
  }
}

int main() {
  memset(count_parent, 0, sizeof count_parent);

  scanf("%d",&n);
  for(int i=0; i<n; i++) {
    cin >> nama[i];
    snama[i] = nama[i];
    if (i>0) {
      bool jalan = true;
      for (int j=0; bisa && jalan; j++) {
        if (j >= nama[i].length()) { bisa = false; }
        else if (j >= nama[i-1].length()) { jalan = false; }
        else if (nama[i][j] != nama[i-1][j]) {
          to[nama[i-1][j]-'a'].pb(nama[i][j]-'a');
          count_parent[nama[i][j]-'a']++;
          jalan = false;
        }
      }
    }
  }
  if (!bisa) {
    printf("Impossible\n");
    return 0;
  }
  bool gaperlu = true;
  for (int i=0; i<26; i++) {
    for (int j=0; j<to[i].size(); j++) {
      if (to[i][j] < i) gaperlu = false;
    }
  }
  if (gaperlu) {
    printf("abcdefghijklmnopqrstuvwxyz\n");
    return 0;
  }
  for (int i=0; i<26; i++) {
    if (count_parent[i] == 0) {
      ans += (char) (i+'a');
    }
  }
  for (int i=0; i<26; i++) {
    if (count_parent[i] == 0) {
      topo(i);
    }
  }

  if (ans.length() < 26) {
    printf("Impossible\n");
    return 0;
  }
  cout << ans << "\n";
}
