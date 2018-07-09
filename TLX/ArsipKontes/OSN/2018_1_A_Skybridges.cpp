#include <bits/stdc++.h>
#define MAXN 100005
#define MAXK 100005
#define MOD 1000000007
#define KIRI 0
#define KANAN 1
using namespace std;

char subsoal[10];
int n, k;
int h[MAXK];
int a[MAXN];
int b[MAXN];

int atas[MAXK][2];
int bawah[MAXK][2];
int tengah[MAXK][2];
long long fact[MAXN];

void coba() {
  int ar[] = {0, 1, 2, 3, 4};
  int cnt = 1;
  next_permutation(ar, ar+5);
  do {
    bool bisa = true;
    for (int i=0; i<5; i++) {
      if (!((ar[i] < 2 && i >= 2) || (ar[i] > 2 && i<= 2) || ar[i] == 2 || i == 2)) bisa = false;
    }
    if (bisa)
      printf ("(%d) %d %d %d %d %d\n", cnt++, ar[0], ar[1], ar[2], ar[3], ar[4]);
  } while (next_permutation(ar, ar+5));
}

int main() {
  memset(atas, 0, sizeof atas);
  memset(bawah, 0, sizeof bawah);
  memset(tengah, 0, sizeof tengah);
  fact[0] = fact[1] = 1;
  for (long long i=2; i<MAXN; i++) {
    fact[i] = i * fact[i-1];
    fact[i] %= MOD;
  }

  scanf("%s", subsoal);
  scanf("%d%d", &n, &k);
  for (int i=0; i<k; i++) { scanf("%d", h+i); h[i]--; }
  for (int i=0; i<n; i++) {
    scanf("%d", a+i); a[i]--;
    if (h[a[i]] == i)     tengah[a[i]][KIRI]++;   // lantai sejajar ama jembatan
    else if (h[a[i]] > i) bawah[a[i]][KIRI]++; // lantai di bawah jembatan
    else                  atas[a[i]][KIRI]++;  // lantai di atas jembatan
  }
  for (int i=0; i<n; i++) {
    scanf("%d", b+i); b[i]--;
    if (h[b[i]] == i)     tengah[b[i]][KANAN]++;   // lantai sejajar ama jembatan
    else if (h[b[i]] > i) bawah[b[i]][KANAN]++; // lantai di bawah jembatan
    else                  atas[b[i]][KANAN]++;  // lantai di atas jembatan
  }

  long long ans = 1;
  for (int i=0; i<k; i++) {
    long long ans_temp = 1;
    int cnt = atas[i][KIRI] + tengah[i][KIRI] + bawah[i][KIRI];

    // printf("%d %d\n%d %d\n%d %d\n\n", atas[i][KIRI], atas[i][KANAN], tengah[i][KIRI], tengah[i][KANAN], bawah[i][KIRI], bawah[i][KANAN]);
    if (atas[i][KIRI] != bawah[i][KANAN]) {
      if (atas[i][KIRI] + tengah[i][KIRI] == bawah[i][KANAN]) {
        atas[i][KIRI] += tengah[i][KIRI];
        tengah[i][KIRI] = 0;
      } else if (atas[i][KIRI] == bawah[i][KANAN] + tengah[i][KANAN]) {
        bawah[i][KANAN] += tengah[i][KANAN];
        tengah[i][KANAN] = 0;
      }
    }
    if (bawah[i][KIRI] != atas[i][KANAN]) {
      if (bawah[i][KIRI] + tengah[i][KIRI] == atas[i][KANAN]) {
        bawah[i][KIRI] += tengah[i][KIRI];
        tengah[i][KIRI] = 0;
      } else if (bawah[i][KIRI] == atas[i][KANAN] + tengah[i][KANAN]) {
        atas[i][KANAN] += tengah[i][KANAN];
        tengah[i][KANAN] = 0;
      }
    }

    // printf("%d %d\n%d %d\n%d %d\n\n", atas[i][KIRI], atas[i][KANAN], tengah[i][KIRI], tengah[i][KANAN], bawah[i][KIRI], bawah[i][KANAN]);
    if (atas[i][KIRI] != bawah[i][KANAN] || bawah[i][KIRI] != atas[i][KANAN]) {
      printf("0\n");
      return 0;
    }

    if (tengah[i][0] == 0 && tengah[i][KANAN] == 0) {
      ans_temp = fact[atas[i][KIRI]] * fact[bawah[i][KIRI]];
      ans_temp %= MOD;
    } else if (tengah[i][KIRI] == 1 && tengah[i][KANAN] == 1) {
      ans_temp = fact[atas[i][KIRI]] * fact[bawah[i][KIRI]];
      ans_temp %= MOD;
      ans_temp *= cnt;
      ans_temp %= MOD;
    }
    ans *= ans_temp;
    ans %= MOD;
  }
  printf("%lld\n", ans);
}