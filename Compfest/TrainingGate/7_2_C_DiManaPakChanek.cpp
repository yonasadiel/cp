/**
 * DiManaPakChanek
 * TL: 1s
 * Determine whether a point is inside or outside polygon.
 * If inside, print the distance to nearest wall
 * Constraints:
 *   1 <= N <= 100 000
 */

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

bool onSegment(point p, point q, point r) {
  return (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) && q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y));
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

  if (x_i <= max(a.x, b.x) && x_i >= min(a.x, b.x) && y_i <= max(a.y, b.y) && y_i >= min(a.y, b.y)) {
    double x_o = (double) o.x;
    double y_o = (double) o.y;
    d = sqrt((x_o - x_i) * (x_o - x_i) + (y_o - y_i) * (y_o - y_i));
  } else {
    d = sqrt(min(dist2(a,o), dist2(b,o)));
  }

  return d;
}

int orientation(point p, point q, point r) {
  long long val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
 
  if (val == 0) return 0;  // colinear
  return (val > 0)? 1: 2; // clock or counterclock wise
}

bool doIntersect(point p1, point q1, point p2, point q2) {
  int o1 = orientation(p1, q1, p2);
  int o2 = orientation(p1, q1, q2);
  int o3 = orientation(p2, q2, p1);
  int o4 = orientation(p2, q2, q1);

  if (o1 != o2 && o3 != o4) {
    return true;
  }

  if (o1 == 0 && onSegment(p1, p2, q1)) return true;
  if (o2 == 0 && onSegment(p1, q2, q1)) return true;
  if (o3 == 0 && onSegment(p2, p1, q2)) return true;
  if (o4 == 0 && onSegment(p2, q1, q2)) return true;

  return false;
}

vector<point> S;

int main() {

  int n;
  point ch, ex;

  scanf("%d",&n);
  for (int i=0; i<n; i++) {
    scanf("%lld%lld", &ch.x, &ch.y);
    S.push_back(ch);
  }

  scanf("%lld%lld", &ch.x, &ch.y);
  ex.x = -1; ex.y = ch.y+1;

  int sz = S.size();
  int cnt = 0;
  double d = -1;

  for (int i=0; i<sz; i++) {
    int i_1 = i; int i_2 = (i+1)%sz;

    if (doIntersect(S[i_1], S[i_2], ch, ex)) {
      if (orientation(S[i_1], ch, S[i_2]) == 0) {
        // on segment
        return -1;
      }
      cnt++;
    }

    double d_temp;

    d_temp = shortest_dist(ch, S[i_1], S[i_2]);

    d = (d == -1)? d_temp : min(d_temp, d);
    
  }

  if (cnt%2 == 0) {
    printf("-1\n");
  } else {
    printf("%.7lf\n", d);
  }
  return 0;
}