#include <cstdio>
#include <cmath>
#include <utility>
#include <vector>
#include <algorithm>
#define point pair<long long,long long>
#define x first
#define y second
#define mp make_pair
using namespace std;

long long dist2(point a, point b) {
  return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

double shortest_dist(point o, point a, point b) {
  long long a_ab = b.y - a.y;
  long long b_ab = a.x - b.x;
  long long c_ab = a_ab * a.x + b_ab * a.y;

  long long a_o = b_ab * -1;
  long long b_o = a_ab;
  long long c_o = a_o * o.x + b_o * o.y;

  double det = a_ab * b_o - a_o * b_ab;
  double x_i = (b_o * c_ab - b_ab * c_o) * 1.0 / det;
  double y_i = (a_ab * c_o - a_o * c_ab) * 1.0 / det;

  double d;

  if (x_i <= max(a.x, b.x) && x_i >= min(a.x, b.x) &&
      y_i <= max(a.y, b.y) && y_i >= min(a.y, b.y)) {
    double x_o = (double) o.x;
    double y_o = (double) o.y;
    d = sqrt((x_o - x_i) * (x_o - x_i) + (y_o - y_i) * (y_o - y_i));
  } else {
    d = sqrt(min(dist2(a,o), dist2(b,o)));
  }

  return d;
}

int main() {
  point pd, p1, p2;

  scanf("%lld%lld", &pd.x, &pd.y);
  scanf("%lld%lld%lld%lld", &p1.x, &p1.y, &p2.x, &p2.y);

  printf("%.7lf\n", shortest_dist(pd, p1, p2));
}