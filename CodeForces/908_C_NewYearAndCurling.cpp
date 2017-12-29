#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

int n;
double r;
double ax[1005], ay[1005];

int main() {
  scanf("%d%lf",&n,&r);
  for (int i=0; i<n; i++) {
    scanf("%lf",&ax[i]);
  }

  for (int i=0; i<n; i++) {
    ay[i] = r;
    for (int j=0; j<i; j++) {
      if (ax[i] <= ax[j] + 2*r && ax[i] >= ax[j] - 2*r) {
        double newy = sqrt(4*r*r - (ax[i]-ax[j])*(ax[i]-ax[j])) + ay[j];
        ay[i] = max(ay[i], newy);
      }
    }
  }

  for (int i=0; i<n; i++) {
    printf("%.8lf", ay[i]);
    if (i < n-1) printf(" ");
    else printf("\n");
  }
}