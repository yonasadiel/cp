#include <cstdio>
#define max(a,b) ((a > b)? (a) : (b))
#define min(a,b) ((a < b)? (a) : (b))
using namespace std;

int a,b,c;

int main() {
  scanf("%d%d%d",&a,&b,&c);
  if (a == 1 || b == 1 || c == 1) {
    printf("YES\n");
  } else if (a == 2 && b == 2) {
    printf("YES\n");
  } else if (a == 2 && c == 2) {
    printf("YES\n");
  } else if (c == 2 && b == 2) {
    printf("YES\n");
  } else if (a == 3 && b == 3 && c == 3) {
    printf("YES\n");
  } else if (min(a,min(b,c)) == 2 && max(a,max(b,c)) == 4 && a+b+c == 10)  {
    printf("YES\n");
  } else {
    printf("NO\n");
  }
}