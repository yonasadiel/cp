#include <cstdio>
using namespace std;

int n;
int card[50];
int sum;
int x;

int main() {
  for (int i=2; i<=11; i++) { card[i] = 4; } card[10] = 16;

  sum = 0;
  scanf("%d",&n);
  for (int i=0; i<n; i++) {
    scanf("%d",&x);
    card[x]--;
    sum += x;
  }

  int cntle = 0;
  int cntgt = 0;
  for (int i=2; i<=11; i++) {
    if (i <= 21-sum) {
      cntle += card[i];
    } else {
      cntgt += card[i];
    }
  }

  //printf("%d %d\n", cntle, cntgt);
  if (cntle > cntgt) {
    printf("VUCI\n");
  } else {
    printf("DOSTA\n");
  }

}