#include <cstdio>
#include <cstring>
#include <algorithm>
#include <utility>
#include <iostream>
#define ll long long
using namespace std;

int na, nb;
string dump;
string osa[1005], osb[1005];
ll va[1005], vb[1005];
pair<ll,int> dp[1005][1005];

pair<ll,int> maxp(pair<ll,int> a, pair<ll,int>b) {
  if (a.first != b.first) {
    return (a.first > b.first)? a : b;
  } else {
    return (a.second > b.second)? b : a;
  }
}

pair<ll,int> ngedp(int a, int b) {
  pair<ll,int> &ret = dp[a][b];
  if (ret.first == -1LL) {
    if (a == na && b == nb) {
      ret = make_pair(0,0);
    } else {
      if (a != na && b != nb && osa[a] == osb[b] && va[a]+vb[b] > 0) {
        ret = make_pair(va[a] + vb[b], 1);
      } else {
        ret = make_pair(0LL,0);
      }

      pair<ll,int> atas = (a == na)? make_pair(0LL,0) : ngedp(a+1, b);
      pair<ll,int> bawah = (b == nb)? make_pair(0LL,0) : ngedp(a, b+1);
      pair<ll,int> maju = (a == na || b == nb)? make_pair(0LL,0) : ngedp(a+1,b+1);

      ret = maxp(make_pair(maju.first+ret.first, maju.second+ret.second), maxp(atas,bawah));
      
    }
  }
  return ret;
}

int main() {
  int cases;
  scanf("%d",&cases);
  while (cases--) {
    for (int i=0; i<1005; i++) {
      for (int j=0; j<1005; j++) {
        dp[i][j] = make_pair(-1LL, 0);
      }
    }

    scanf("%d",&na);
    for (int i=0; i<na; i++) {
      cin >> dump >> osa[i];
      scanf("%lld",&va[i]);
    }
    scanf("%d",&nb);
    for (int i=0; i<nb; i++) {
      cin >> dump >> osb[i];
      scanf("%lld",&vb[i]);
    }

    pair<ll,int> ret = ngedp(0,0);
    printf("%lld %d\n", ret.first, ret.second);

  }
}