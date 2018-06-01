#include <cstdio>
#define div_round_up(a,b) ((a)+(b)-1)/(b)
using namespace std;

int main() {
  int t;
  scanf("%d",&t);
  while(t--) {
    int a,b,k;
    scanf("%d%d%d",&a,&b,&k);
    bool bisa=false;
    char p = 'P';
    char l = 'L';

    if (a > b) {
      k = b;
      b = a;
      a = k;
      p = 'L';
      l = 'P';
      k = 2;

    }

    int perblok = -1;
    int sisa = -1;
    int blok = -1;

    // kalo dua ujung cewek
    if (!bisa) {
      if (div_round_up(b, a+1) <= k && b / (a+1) > 0) {
        bisa = true;
        perblok = b / (a+1);
        sisa = b % (a+1);
        blok = a+1;

        for (int i=0; i<perblok; i++) { printf("%c", p); }
        if (sisa > 0) { printf("%c", p); sisa--; }
        for (int j=0; j<a; j++) {
          printf("%c", l);
          for (int i=0; i<perblok; i++) { printf("%c", p); }
          if (sisa > 0) { printf("%c", p); sisa--; }
        }
      }
    }

    // kalo satu ujung cewek
    if (!bisa) {
      if (a > 0 && div_round_up(b, a) <= k && b / (a) > 0) {
        bisa = true;
        perblok = b / (a);
        sisa = b % a;
        blok = a;

        for (int j=0; j<a; j++) {
          printf("%c", l);
          for (int i=0; i<perblok; i++) { printf("%c", p); }
          if (sisa > 0) { printf("%c", p); sisa--; }
        }
      }
    }

    // kalo dua ujung cowok
    if (!bisa) {
      if (a > 1 && div_round_up(b, a-1) <= k && b / (a-1) > 0) {
        bisa = true;
        perblok = b / (a-1);
        sisa = b % (a-1);
        blok = a-1;

        for (int j=0; j<a-1; j++) {
          printf("%c", l);
          for (int i=0; i<perblok; i++) { printf("%c", p); }
          if (sisa > 0) { printf("%c", p); sisa--; }
        }
        printf("%c", l);
      }
    }

    if (!bisa) {
      printf("mustahil");
    }
    printf("\n");
  }
}