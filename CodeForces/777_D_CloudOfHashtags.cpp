#include <cstdio>
#include <iostream>
using namespace std;

int n;
string h[500005];
int l[500005];

int main() {
  scanf("%d",&n);
  for (int i=0; i<n; i++) {
    cin >> h[i];
  }

  l[n-1] = h[n-1].length();
  for (int i=n-2; i>=0; i--) {
    l[i] = 1;
    for (int j=1; j<min(h[i].length(), h[i+1].length()) && j < l[i+1]; j++) {
      if (h[i][j] > h[i+1][j]) {
        break;
      } else if (h[i][j] < h[i+1][j]) {
        l[i] = h[i].length();
        break;
      }
      l[i]++;
    }
  }

  for (int i=0; i<n; i++) {
    for (int j=0; j<l[i]; j++) {
      printf("%c", h[i][j]);
    } printf("\n");
  }
}