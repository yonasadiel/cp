#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pii pair<int, int>
#define MOD 1000000007
#define vi vector<int>
using namespace std;

int dp[5005][5005];

int main() {
    int n;
    string s1, s2;
    scanf("%d", &n);
	cin >> s1;
	s2 = s1;
	reverse(s2.begin(), s2.end());

	for (int i=0; i<=n; i++) {
		for (int j=0; j<=n; j++) {
			if (i == 0 && j == 0) {
				dp[i][j] = 0;
			} else if (i > 0 && j == 0) {
				dp[i][j] = dp[i-1][j];
			} else if (i == 0 && j > 0) {
				dp[i][j] = dp[i][j-1];
			} else {
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
				if (s1[i-1] == s2[j-1]) {
					dp[i][j] = 1+dp[i-1][j-1];
				}
			}
        }
	}
	printf("%d\n", n-dp[n][n]);
}