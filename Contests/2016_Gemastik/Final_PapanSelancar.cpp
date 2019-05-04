#include <cstdio>
#include <cstring>
using namespace std;

long long tambah[50005];

void docase() {
  memset(tambah, 0, sizeof tambah);

  int n,m,x,k;
  long long start = 0;
  scanf("%d%d",&n,&m);
  for (int i=0; i<m; i++) {
    scanf("%d%d",&k,&x);
    if (k < x) { start += x-k; tambah[1] += 1; }
    else       { tambah[k-x+1] += 1; }

    if (k < n) { tambah[k+1] -= 2; }

    if (k+x < n) { tambah[k+x+1] += 1; }

  }

  long long run = start;
  long long t_tambah = 0;
  for (int i=1; i<=n; i++) {
    t_tambah += (long long) tambah[i];
    run += t_tambah;
    printf("%lld", run);

    if (i!=n) printf(" ");
    else      printf("\n");
  }

}

int main() {
  int t;
  scanf("%d",&t);
  while (t--) {
    docase();
  }
}