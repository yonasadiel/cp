#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>
#include <cstring>

int CeilIndex(std::vector<int> &v, int l, int r, int key) {
    while (r-l > 1) {
    int m = l + (r-l)/2;
    if (v[m] >= key)
        r = m;
    else
        l = m;
    }

    return r;
}

std::pair<int,int> LongestIncreasingSubsequenceLength(std::vector<int> &v) {
    if (v.size() == 0)
        return std::make_pair(0, 0);

    std::vector<int> tail(v.size(), 0);
    int length = 1;

    tail[0] = v[0];
    for (size_t i = 1; i < v.size(); i++) {
        if (v[i] < tail[0])
            tail[0] = v[i];
        else if (v[i] > tail[length-1])
            tail[length++] = v[i];
        else
            tail[CeilIndex(tail, -1, length-1, v[i])] = v[i];
    }

    return std::make_pair(length, tail[length-1]);
}

bool exist[400005];

void solve() {
    int n, x;
    std::vector<int> v1, v2;
    memset(exist, false, sizeof exist);
    scanf("%d", &n);
    for (int i=0; i<n*n; i++) {
        scanf("%d", &x);
        if (x > 0 && x < 400005) exist[x] = true;

        v1.push_back(x);
        v2.push_back(-x);
    }

    std::pair<int,int> rlis = LongestIncreasingSubsequenceLength(v1);
    std::pair<int,int> rlds = LongestIncreasingSubsequenceLength(v2);

    int lis = rlis.first;
    int lds = rlds.first;
    int ma = rlis.second;
    int mi = rlds.second;

    if (lds > n || lis > n) {
        printf("0\n");
    } else {
        if (lds != n || lis != n) {
            exit(3);
        }
        printf("1\n");

        int min_non_exist_val = 1;
        while (exist[min_non_exist_val]) {
            min_non_exist_val++;
        }
        printf("%d\n", min_non_exist_val);
    }
    v1.clear();
    v2.clear();
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) solve();
   return 0;
}