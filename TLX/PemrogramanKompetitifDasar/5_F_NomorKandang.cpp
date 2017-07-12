#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int n;
long long cost[10];
long long uang;
int csort[] = {0,1,2,3,4,5,6,7,8,9};
long long dibeli[10];

bool cmp(int le, int ri) {
  return cost[le] < cost[ri];
}

int main() {
  memset(dibeli, 0, sizeof dibeli);

  scanf("%d",&n);
  for (int i=0; i<=n; i++) {
    scanf("%lld",&cost[i]);
  }
  scanf("%lld",&uang);

  sort(csort, csort + n + 1, cmp);

  if (uang < cost[csort[0]]) {
    printf("0\n");
  } else if (n == 0 || (csort[0] == 0 && uang < cost[csort[1]])) {
    printf("1\n0\n0\n");
  } else {
    int indbeli = (csort[0] == 0)? csort[1] : csort[0];
    uang -= cost[indbeli];
    dibeli[indbeli]++;

    long long jmlbeli = uang / cost[csort[0]];
    uang -= jmlbeli * cost[csort[0]];
    dibeli[csort[0]] += jmlbeli;

    for (int i=n, lo=0; i>=0 && i > lo;) {
      long long diffcost = cost[csort[i]] - cost[csort[lo]];
      long long cobabeli = (diffcost == 0) ? dibeli[csort[lo]] : min(uang / diffcost, dibeli[csort[lo]]);
      uang -= (long long) cobabeli * diffcost;
      dibeli[csort[i]] += cobabeli;
      dibeli[csort[lo]] -= cobabeli;
      if (dibeli[csort[lo]] == 0) {
        lo++;
      } else {
        i--;
      }
    }

    long long sum = 0;
    for (int i=0; i<=n; i++) { sum += dibeli[i]; }
    printf("%lld\n",sum);

    for (int c=0, i=n; i>=0 && c<50; i--) {
      long long out = min((long long) 50-c, dibeli[i]);
      for (int j=0; j<out; j++) { printf("%d", i); c++; }
    }

    printf("\n");

    int keluar[50]; int last = 0;
    for (int c=0, i=0; i<10 && c<50; i++) {
      long long out = min((long long) 50-c, dibeli[i]);
      for (int j=0; j<out; j++) { keluar[c] = i; c++; last = c;}
    }
    for (int i=last-1; i>=0; i--) { printf("%d", keluar[i]); }

    printf("\n");

  }
}