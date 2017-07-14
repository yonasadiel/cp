/**
 * Karpet
 * TL: 1s
 * Calculate area of polygon using shoelace formula
 */

#include <cstdio>
#include <cmath>
using namespace std;

int n;
double arr_x[100005];
double arr_y[100005];

int main() {
  scanf("%d",&n);
  for (int i=0; i<n; i++) {
    scanf("%lf%lf", &arr_x[i], &arr_y[i]);
  }
  
  double area = 0;
  for (int i=0; i<n; i++) {
    area += arr_x[i] * arr_y[(i+1)%n] - arr_x[(i+1)%n] * arr_y[i];
  }
  area = abs(area) * 1.0 / 2;

  printf("%.1lf\n", area);
}