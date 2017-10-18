#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
  int a[3][3];
  int sum = 0;
  for (int i=0; i<3; i++) {
    for (int j=0; j<3; j++) {
      scanf("%d",&a[i][j]);
    }
    int get = a[i][0];
    for (int j=0; j<3; j++) {
      get = min(get, a[i][j]);
    }
    sum += get;
  }

  printf("%d\n", sum);

}