#include <cstdio>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

void docase() {
    int n,k;
    set <string> nama;
    string dmp;
    int ans_min = 0;

    scanf("%d",&n);
    while (n--) {
      cin >> dmp;
      scanf("%d",&k);
      if (dmp == "dibantu") { ans_min = max(k+1, ans_min); }

      for (int i=0; i<k; i++) {
        cin >> dmp;
        nama.insert(dmp);
      }

    }

    printf("%d\n", max(ans_min, (int) nama.size()));
}

int main() {
  int ncase;
  scanf("%d",&ncase);
  while(ncase--) {
    docase();
  }
}