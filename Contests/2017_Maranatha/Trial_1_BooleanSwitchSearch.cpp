#include <cstdio>
#include <iostream>
using namespace std;

int main() {
  string ans;
  int t,n,a;
  scanf("%d",&t);
  while (t--) {
    scanf("%d",&n);
    for (int i=1; i<n-1; i++) {
      printf("READ %d\n", i);
      cin>>ans;
      if (ans == "true") {
        a = i;
      } else {
        if (a == i-1) {
          printf("OUTPUT %d\n",a);
          return 0;
        }
      }
    }
  }
}