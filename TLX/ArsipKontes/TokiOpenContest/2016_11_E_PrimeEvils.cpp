#include<bits/stdc++.h>
using namespace std;

int main() {
  int n;
  int s=0, g=0;
  int sl=0, gl=0;
  string sinp;

  scanf("%d",&n);
  for (int i=1; i<=n; i++) {
    if (s == g) {
        printf("%d SAITAMA\n",i);
        fflush(stdout);

        cin>>sinp;
        if (sinp == "SERI") {
          gl++;
        } else {
          sl++;
          s++;
        }
    } else if (s < g) {
        printf("%d SAITAMA\n",i);
        fflush(stdout);

        cin>>sinp;
        if (sinp == "GENOS") {
          gl++;
        } else {
          sl++;
          s++;
        }
    } else /*s > g*/ {
      printf("%d GENOS\n",i);
      fflush(stdout);

      cin>>sinp;
      if (sinp == "SAITAMA") {
        sl++;
      } else if (sinp == "SERI"){
        gl++;
        g++;
      }
    }
  }
  printf("%d %d\n",sl,gl);
  fflush(stdout);
}
