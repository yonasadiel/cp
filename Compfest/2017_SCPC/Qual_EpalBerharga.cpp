#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int n;
int    arr[100005];
bool sudah[100005];
int    brr[100005];

bool valid(int tebak) {
  memset(sudah, false, sizeof sudah);
  for (int i=0; i<n; i++) { brr[i] = arr[i]; }
  int last_sudah = -1;
  for (int i=0; i<n; i++) {
    int incr = 0;
    if (brr[i] < tebak) {
      while (brr[i] < tebak) {
        if ((i > 0 && !sudah[i-1] && brr[i-1] > tebak)) {
          // ambil kiri
          sudah[i-1] = true;
          brr[i]++;
          brr[i-1]--;
        } else if (i+1 < n && !sudah[i+1]) {
          // ambil kanan
          sudah[i+1] = true;
          brr[i]++;
          brr[i+1]--;
        } else {
          return false;
        }
      }
    } else if (brr[i] > tebak && !sudah[i]) {
      sudah[i] = true;
      brr[i]--;
      brr[i+1]++;
    }
  }
  return true;
}

int binser(int lo) {
  for (int mi = lo; mi < lo+10; mi++) {
    if (!valid(mi)) {
      return mi-1;
    }
  }
  while(1);
}

void percase() {
  scanf("%d",&n);
  int lot = 0;
  for (int i=0; i<n; i++) {
    scanf("%d",&arr[i]);
    if (arr[lot] > arr[i]) { lot = i; }
  }

  printf("%d\n", binser(arr[lot]));
}

int main() {
  int t;
  scanf("%d",&t);
  while (t--) {
    percase();
  }
}