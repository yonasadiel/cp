#include <bits/stdc++.h>
#define ll long long
using namespace std;

bool ditanya[120];
string temp[120];

bool solve(int tc) {
    char ans[6];
    memset(ditanya, true, sizeof(ditanya));
    int counter[6];
    int nanya = 0;
    for (int nround = 1; nround <= 3; nround++) {
        memset(counter, 0, sizeof counter);
        for (int i = 0; i < 119; i++) {
            if (ditanya[i]) {
                cout << i * 5 + nround << endl;
                nanya++;
                cin >> temp[i];
                counter[temp[i][0] - 'A']++;
            }
        }
        int should = 0;
        for (char cc = 'A'; cc <= 'E'; cc++) {
            should = max(should, counter[cc - 'A']);
        }
        for (char cc = 'A'; cc <= 'E'; cc++) {
            if (counter[cc - 'A'] == should - 1) ans[nround - 1] = cc;
        }
        // fprintf(stderr,"%d: %c\n", nround, ans[nround - 1]);
        for (int i = 0; i < 119; i++) {
            if (temp[i][0] != ans[nround - 1]) {
                ditanya[i] = false;
            }
        }
    }
    bool exist[6];
    memset(exist, false, sizeof exist);
    exist[ans[0] - 'A'] = true;
    exist[ans[1] - 'A'] = true;
    exist[ans[2] - 'A'] = true;
    for (int i = 0; i < 119; i++) {
        if (ditanya[i]) {
            string last;
            cout << i * 5 + 4 << endl;
            nanya++;
            cin >> last;
            exist[last[0] - 'A'] = true;
            ans[4] = last[0];
        }
    }
    for (char cc = 'A'; cc <= 'E'; cc++) {
        if (!exist[cc - 'A']) ans[3] = cc;
    }
    ans[5] = '\0';
    printf("%s\n", ans);
    string judge;
    cin >> judge;
    return (judge != "N");
}

int main() {
    int t, f;
    cin >> t >> f;
    for (int i=1; i<=t; i++) {
        if (!solve(i)) {
            break;
        }
    }
}