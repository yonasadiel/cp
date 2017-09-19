#include <cstdio>
#include <iostream>
using namespace std;

int main() {
  int n;
  long long k;
  scanf("%d%I64d",&n,&k);

  long long level = 0;
  string s = "";

  int used = 0;
  while ((k || level) && used <= n) {
    if (k >= level) {
      s += "(";
      k -= level;
      level++;
      used++;
    } else {
      s += ")";
      level--;
    }
    //cout << level << " " << k << " " << s <<endl;
  }

  if (used <= n) {
    cout << s;
    n -= used;
    while (n--) {
      printf("()");
    }
    printf("\n");
  } else {
    printf("Impossible\n");
  }
}