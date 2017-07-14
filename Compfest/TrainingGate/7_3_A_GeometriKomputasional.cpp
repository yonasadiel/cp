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

long long cross (point a, point b, point c) {
  return (a.x - b.x) * (c.y - b.y) - (a.y - b.y) * (c.x - b.x);
}

bool collinear (point a, point o, point b) {
  return cross(a, o, b) == 0;
}

// ganti di sini buat ganti arah
bool ccw (point a, point o, point b) {
  return cross(a, o, b) > 0;
}

point pivot;

long long dist2(point a, point b) {
  return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

bool angle_cmp(point a, point b) {
  if (collinear(pivot, a, b)) {
    return dist2(a, pivot) < dist2(b, pivot);
  }
  return ccw(pivot, a, b);
}

// ganti di sini untuk urutan titik, berdasar x dulu atau y dulu
bool cmp(point a, point b) {
  return (a.y < b.y) || (a.y == b.y && a.x < b.x);
}

vector<point> P, S;
// P is going-to-be convex hull, result will be stored in S.

void convexHull() {
  int n = (int) P.size();
  if (n < 3) return;

  int PO = 0; // index of most left-bottom point
  for (int i=1; i<n; i++) {
    if (cmp(P[i], P[PO])) {
      PO = i;
    }
  }
  swap(P[0], P[PO]);
  pivot = P[0];

  sort(P.begin()+1, P.end(), angle_cmp);

  for (int i=0, sz=0; i<n; ) {
    if (sz < 2 || ccw(S[sz-2], S[sz-1], P[i])) {
      S.push_back(P[i]); sz++; i++;
    } else {
      S.pop_back();
      sz--;
    }
  }
}

int main() {
  int n;
  long long a;
  long long b;

  scanf("%d",&n);
  for (int i=0; i<n; i++) {
    scanf("%lld%lld", &a, &b);
    P.push_back(mp(a,b));
  }

  convexHull();

  // output keliling
  double ret = sqrt(1.0 * dist2(S[0], S[S.size()-1]));
  for (int i=1; i<S.size(); i++) {
    ret += sqrt(1.0 * dist2(S[i], S[i-1]));
  }
  printf("%.7lf\n", ret);

}