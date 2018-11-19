#include <bits/stdc++.h>
using namespace std;

int n;
int a[100005];
int dp[100005][10];
int pred[100005][10];

int main() {
    scanf("%d", &n);
    for (int i=0; i<n; i++) {
        scanf("%d", &a[i]);
    }

    for (int pos=0; pos<n; pos++) {
        for (int finger=1; finger<=5; finger++) {
            int &ret = dp[pos][finger];
            if (pos == 0) {
                ret = 1;
            } else {
                ret = 0;
                if (a[pos] < a[pos-1]) {
                    for (int i=finger+1; i<=5; i++) {
                        if (dp[pos-1][i] > 0) {
                            pred[pos][finger] = i;
                            ret = dp[pos-1][i];
                        }
                    }
                } else if (a[pos] > a[pos-1]) {
                    for (int i=1; i<finger; i++) {
                        if (dp[pos-1][i] > 0) {
                            pred[pos][finger] = i;
                            ret = dp[pos-1][i];
                        }
                    }
                } else {
                    for (int i=1; i<=5; i++) {
                        if (i != finger) {
                            if (dp[pos-1][i] > 0) {
                                pred[pos][finger] = i;
                                ret = dp[pos-1][i];
                            }
                        }
                    }
                }
            }
        }
    }

    vector<int> v;
    for (int i=1; i<=5; i++) {
        if (dp[n-1][i] > 0) {
            int pos = n-1, finger=i;
            while (pos >= 0) {
                v.push_back(finger);
                finger = pred[pos][finger];
                pos--;
            }
            for (int i=v.size()-1; i>=0; i--) {
                printf("%d%c", v[i], (i == 0 ? '\n' : ' '));
            }
            return 0;
        }
    }
    printf("-1\n");
}
