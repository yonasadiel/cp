#include <cstdio>
#include <algorithm>
#include <iostream>
#define fi first
#define se second.first
#define th second.second
#define ttim pair<string, pair<long long, long long> >
using namespace std;

ttim timc[50005];
ttim timg[50005];

bool dsc_c(ttim a, ttim b) { return a.se > b.se; }
bool dsc_g(ttim a, ttim b) { return a.th > b.th; }

void docase() {
  int n;
  scanf("%d",&n);
  for (int i=0; i<n; i++) {
    cin >> timc[i].fi;
    scanf("%lld%lld", &timc[i].se, &timc[i].th);

    timg[i].fi = timc[i].fi;
    timg[i].se = timc[i].se;
    timg[i].th = timc[i].th;
  }

  sort(timc, timc + n, dsc_c);
  sort(timg, timg + n, dsc_g);

  long long m = 1;
  int ans_c_a, ans_c_b, ans_c_c, ans_g_a, ans_g_b, ans_g_c;

  for (int i_c_a =       0; i_c_a < 6; i_c_a++) {
  for (int i_c_b = i_c_a+1; i_c_b < 6; i_c_b++) {
  for (int i_c_c = i_c_b+1; i_c_c < 6; i_c_c++) {
  for (int i_g_a =       0; i_g_a < 6; i_g_a++) {
  for (int i_g_b = i_g_a+1; i_g_b < 6; i_g_b++) {
  for (int i_g_c = i_g_b+1; i_g_c < 6; i_g_c++) {
    if (timc[i_c_a].fi != timg[i_g_a].fi && timc[i_c_a].fi != timg[i_g_b].fi && timc[i_c_a].fi != timg[i_g_c].fi &&
        timc[i_c_b].fi != timg[i_g_a].fi && timc[i_c_b].fi != timg[i_g_b].fi && timc[i_c_b].fi != timg[i_g_c].fi &&
        timc[i_c_c].fi != timg[i_g_a].fi && timc[i_c_c].fi != timg[i_g_b].fi && timc[i_c_c].fi != timg[i_g_c].fi) {
      long long tes = (long long) timc[i_c_a].se*timc[i_c_b].se*timc[i_c_c].se + timg[i_g_a].th*timg[i_g_b].th*timg[i_g_c].th;
      if (tes > m) {
        m = tes;
        ans_c_a = i_c_a; ans_c_b = i_c_b; ans_c_c = i_c_c;
        ans_g_a = i_g_a; ans_g_b = i_g_b; ans_g_c = i_g_c;
      }
    }
  } } } } } }

  printf("%lld\n", m);
  cout << timc[ans_c_a].fi << " " << timc[ans_c_b].fi << " " << timc[ans_c_c].fi << endl;
  cout << timg[ans_g_a].fi << " " << timg[ans_g_b].fi << " " << timg[ans_g_c].fi << endl;
}

int main() {
  int t;
  scanf("%d",&t);
  while (t--) {
    docase();
  }
}