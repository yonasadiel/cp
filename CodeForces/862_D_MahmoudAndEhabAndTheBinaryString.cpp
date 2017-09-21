#include <iostream>
#include <cstdio>
using namespace std;

int n;
int pertama;

int main() {
  int n;
  scanf("%d",&n);

  int a,b;
  printf("? " ); for (int i=0; i<n; i++) { printf("0"); } printf("\n"); fflush(stdout); scanf("%d",&a);
  printf("? 1"); for (int i=1; i<n; i++) { printf("0"); } printf("\n"); fflush(stdout); scanf("%d",&b);

  if (b > a) { pertama = 0; }
  else       { pertama = 1; }

  if (pertama == 0) {
    int lo = 1;
    int hi = n-1;

    while (lo < hi) {
      int mi = (lo+hi)/2;

      printf("? ");
      for (int i=0; i<n; i++) {
        if (i >= lo && i <= mi) { printf("1"); }
        else                    { printf("0"); }
      }
      printf("\n");
      fflush(stdout);

      scanf("%d", &b);

      if (b-a == mi-lo+1) {
        lo = mi+1;
      } else {
        hi = mi;
      }
    }

    printf("! %d %d\n", 1, lo+1);
    fflush(stdout);
  } else {
    printf("? " ); for (int i=0; i<n; i++) { printf("1"); } printf("\n"); fflush(stdout); scanf("%d",&a);

    int lo = 1;
    int hi = n-1;

    while (lo < hi) {
      int mi = (lo+hi)/2;

      printf("? ");
      for (int i=0; i<n; i++) {
        if (i >= lo && i <= mi) { printf("0"); }
        else                    { printf("1"); }
      }
      printf("\n");
      fflush(stdout);

      scanf("%d", &b);

      if (b-a == mi-lo+1) {
        lo = mi+1;
      } else {
        hi = mi;
      }
    }

    printf("! %d %d\n", lo+1, 1);
    fflush(stdout); 
  }


}