#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

int r,c,h,w,t;
char pet[105][105];
int row[105];
int col[105];
vector<int> cr, cc;

void exec(int tc) {
	memset(row, 0, sizeof row);
	memset(col, 0, sizeof col);
	t = 0;
	cr.clear(); cr.push_back(-1);
	cc.clear(); cc.push_back(-1);

	scanf("%d%d%d%d\n", &r,&c,&w,&h);
	for (int i=0; i<r; i++) {
		for (int j=0; j<c; j++) {
			scanf("%c", &pet[i][j]);
			if (pet[i][j] == '@') { row[i]++; col[j]++; t++; }
		} scanf("\n");
	}

	bool bisa = (t % (h+1) == 0) && (t % (w+1) == 0);
	if (!bisa) { printf("Case #%d: IMPOSSIBLE\n", tc); return; }
	int goal = t / (h+1);
	int last = 0;
	for (int i=0; bisa && i<c; i++) {
		last += col[i];
		if (last == goal) {
			last = 0;
			cc.push_back(i);
		} else if (last > goal) {
			bisa = false;
		}
	}
	bisa = bisa && (last == 0);

	goal = t / (w+1);
	last = 0;
	for (int i=0; bisa && i<r; i++) {
		last += row[i];
		if (last == goal) {
			last = 0;
			cr.push_back(i);
		} else if (last > goal) {
			bisa = false;
		}
	}
	if (!bisa) { printf("Case #%d: IMPOSSIBLE\n", tc); return; }

	for (int i=1; i<cr.size(); i++) {
		for (int j=1; j<cc.size(); j++) {
			int cnt = 0;
			//fprintf(stderr, "%d %d %d %d\n", cr[i-1]+1, cc[i-1]+1, cr[i], cc[j]);
			for (int ii=cr[i-1]+1; ii<=cr[i]; ii++) {
				for (int jj=cc[j-1]+1; jj<=cc[j]; jj++) {
					if (pet[ii][jj] == '@') cnt++;
				}
			}
			if (cnt != t / (h+1) / (w+1)) { printf("Case #%d: IMPOSSIBLE\n", tc); return; }
		}
	}

	printf("Case #%d: POSSIBLE\n", tc);
}

int main() {
	int tc;
	scanf("%d", &tc);
	for (int i=0; i<tc; i++) {
		exec(i+1);
	}
}