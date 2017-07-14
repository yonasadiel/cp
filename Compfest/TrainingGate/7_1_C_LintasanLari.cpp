#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

double x_1, y_1;
double x_2, y_2;
double x_3, y_3;
double x_4, y_4;

int main() {
  scanf("%lf%lf%lf%lf", &x_1, &y_1, &x_2, &y_2);
  scanf("%lf%lf%lf%lf", &x_3, &y_3, &x_4, &y_4);

  double a_12 = y_2 - y_1;
  double b_12 = x_1 - x_2;
  double c_12 = a_12 * x_1 + b_12 * y_1;

  double a_34 = y_4 - y_3;
  double b_34 = x_3 - x_4;
  double c_34 = a_34 * x_3 + b_34 * y_3;

  double det = a_12 * b_34 - a_34 * b_12;
  if (abs(det) < 1e-9) {
    // paralel
    while (true) { int a = 0; }
  } else {
    double x_i = (b_34 * c_12 - b_12 * c_34) / det;
    double y_i = (a_12 * c_34 - a_34 * c_12) / det;

    if (x_i <= max(x_1, x_2) && x_i <= max(x_3, x_4) &&
        x_i >= min(x_1, x_2) && x_i >= min(x_3, x_4) && 
        y_i <= max(y_1, y_2) && y_i <= max(y_3, y_4) &&
        y_i >= min(y_1, y_2) && y_i >= min(y_3, y_4)) {
      printf("%.7lf %.7lf\n", x_i, y_i);
    } else {
      printf("-1 -1\n");
    }
  }
}