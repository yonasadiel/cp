#include <iostream>
using namespace std;

int n, m;
string s, ss;

int dist[50][50];

void solve(int tc) {
    cin >> s;
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < 26; j++) {
            dist[i][j] = 1000000;
        }
        dist[i][i] = 0;
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> ss;
        dist[ss[0] - 'A'][ss[1] - 'A'] = 1;
        // dist[ss[1] - 'A'][ss[0] - 'A'] = 1;
    }
    for (int k = 0; k < 26; k++) {
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < 26; j++) {
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
    int ans = 1000000;
    for (char tt = 'A'; tt <= 'Z'; tt++) {
        int temp = 0;
        for (char cc : s) {
            temp += dist[cc - 'A'][tt - 'A'];
        }
        if (ans > temp) {
            ans = temp;
            // cout << tt << " " << temp << endl;
        }
    }
    if (ans >= 10000) {
        ans = -1;
    }
    cout << "Case #" << tc << ": " << ans << endl;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        solve(i+1);
    }
}