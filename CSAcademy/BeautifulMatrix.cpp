#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <stack>
#include <map>
#include <set>
#define ll long long
#define pb push_back
#define fi first
#define se second
#define mp make_pair
using namespace std;

int n,m;
int** a;
int** b;
int* baris;
int* kolom;

int main() {
  scanf("%d%d",&n,&m);
  a = (int**) malloc(n*sizeof(int*));
  b = (int**) malloc(n*sizeof(int*));
  for (int i=0; i<n; i++) {
    a[i] = (int*) malloc(m*sizeof(int));
    b[i] = (int*) malloc(m*sizeof(int));
    for (int j=0; j<m; j++) {
      b[i][j] = 0;
      scanf("%d",&a[i][j]);
    }
  }

  for (int i=0; i<n-1; i++)
    for (int j=0; j<m-1; j++)
      b[i][j]++;
  for (int i=0; i<n-1; i++)
    for (int j=0; j<m-1; j++)
      b[i+1][j]++;
  for (int i=0; i<n-1; i++)
    for (int j=0; j<m-1; j++)
      b[i][j+1]++;
  for (int i=0; i<n-1; i++)
    for (int j=0; j<m-1; j++)
      b[i+1][j+1]++;
  
  int ans = 0; int mi, ma, canans;

  /** without swap **/
  for (int i=0; i<n; i++) {
    for (int j=0; j<m; j++) {
      ans += a[i][j] * b[i][j];
    }
  }
  fprintf(stderr, "%d\n", ans);

  /** swapping rows **/
  if (n > 2) {
    baris = (int*) malloc(n*sizeof(int));
    for (int i=0; i<n; i++) {
      baris[i] = 0;
      for (int j=0; j<m; j++) {
        if (j == 0 || j == m-1) { baris[i] += a[i][j]; }
        else { baris[i] += a[i][j]*2; }
      }
      if (i > 0 && i < n-1) baris[i] *= 2;
    }
    mi = 1;
    for (int i=1; i<n-1; i++) {
      if (baris[i] < baris[mi]) { mi = i; }
    }
    ma = 0;
    if (baris[n-1] > baris[ma]) { ma = n-1; }
    canans = 0;
    for (int i=0; i<n; i++) {
      canans += baris[i];
      if (i == ma) { canans += baris[i]; }
      if (i == mi) { canans -= baris[i]/2; }
    }
    ans = max(ans, canans);
    fprintf(stderr, "%d\n", ans);
  }

  /** swapping cols **/
  if (m > 2) {
    kolom = (int*) malloc(m*sizeof(int));
    for (int j=0; j<m; j++) {
      kolom[j] = 0;
      for (int i=0; i<n; i++) {
        if (i == 0 || i == n-1) { kolom[j] += a[i][j]; }
        else { kolom[j] += a[i][j]*2; }
      }
      if (j > 0 && j < m-1) kolom[j] *= 2;
    }
    mi = 1;
    for (int j=1; j<m-1; j++) {
      if (kolom[j] < kolom[mi]) { mi = j; }
    }
    ma = 0;
    if (kolom[m-1] > kolom[ma]) { ma = m-1; }
    canans = 0;
    for (int j=0; j<m; j++) {
      canans += kolom[j];
      if (j == ma) { canans += kolom[j]; }
      if (j == mi) { canans -= kolom[j]/2; }
    }
    ans = max(ans, canans);
    fprintf(stderr, "%d\n", ans);
  }

  /** end **/
  printf("%d\n", ans);

  
}