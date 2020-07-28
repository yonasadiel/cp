#include <bits/stdc++.h>
using namespace std;

void solve(int tc) {
  int n;
  char in[100], ou[100];
  scanf("%d", &n);
  for (int i = 0; i < n; i++) { scanf(" %c", &in[i]); }
  for (int i = 0; i < n; i++) { scanf(" %c", &ou[i]); }

  int dist[100][100];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i == j) {
        dist[i][j] = 0;
      } else if (abs(i - j) <= 1 && ou[i] == 'Y' && in[j] == 'Y') {
        dist[i][j] = 1;
      } else {
        dist[i][j] = 1000;
      }
    }
  }
  for (int k = 0; k < n; k++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (dist[i][k] + dist[k][j] < dist[i][j]) {
          dist[i][j] = dist[i][k] + dist[k][j];
        }
      }
    }
  }
  printf("Case #%d:\n", tc);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      printf("%c", (dist[i][j] < 1000) ? 'Y' : 'N');
    }
    printf("\n");
  }
}

int main() {
  int t;
  scanf("%d", &t);
  for (int i = 1; i <= t; i++) {
    solve(i);
  }
}
