#include <cstdio>
using namespace std;

int n;

int main() {
  scanf("%d",&n);

  if ((n%10 == (n/10)%10 && n%10 == (n/100)%10) ||
      ((n/10)%10 == (n/100)%10 && (n/10)%10 == (n/1000)%10)) {
    printf("Yes\n");
  } else {
    printf("No\n");
  }

}