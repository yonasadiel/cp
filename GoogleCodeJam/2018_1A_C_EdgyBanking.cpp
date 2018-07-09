#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

void exec(int tc) {
	int n, d;
	double bisa = 0;
	double p, w, h, a, b, c, bb, cc;
	scanf("%d %lf", &n,&p);

	a = c = 0;
	for (int i=0; i<n; i++) {
		scanf("%lf%lf", &w, &h);
		a += 2*w + 2*h;
	}
	p -= a;
	bb = b = min(2*w, 2*h);
	cc = c = 2*sqrt(w*w+h*h);
	d = 0;

	while (d < n) {
		if (bb <= p && p <= cc) bisa = p;
		else if (cc <= p) bisa = cc;
		bb += b; cc += c;
		d++;
	}

	printf("Case #%d: %.8lf\n", tc, a+bisa);
}

int main() {
	int tc;
	scanf("%d", &tc);
	for (int i=1; i<=tc; i++) {
		exec(i);
	}
}