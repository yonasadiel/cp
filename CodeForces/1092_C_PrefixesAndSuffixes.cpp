#include <bits/stdc++.h>
using namespace std;

int n;
string s[205];
int sudah[205];

bool comp(const string& a, const string& b) {
    return a.length() < b.length();
}

bool is_suffix(const string& suff, const string& word) {
    for (int i = 0; i < suff.length(); i++) {
        if (word[word.length() - i - 1] != suff[suff.length() - i - 1]) {
            return false;
        }
    }
    return true;
}

bool is_prefix(const string& pref, const string& word) {
    for (int i = 0; i < pref.length(); i++) {
        if (word[i] != pref[i]) {
            return false;
        }
    }
    return true;
}

int main() {
    cin >> n;
    int m = 2 * n - 2;
    for (int i = 0; i < m; i++) {
        cin >> s[i];
    }

    memset(sudah, -1, sizeof sudah);

    string a[2];
    int na = 0;
    for (int i = 0; i < m; i++) {
        if (s[i].length() == n - 1) {
            a[na] = s[i];
            na++;
        }
    }
    string p1, p2;
    p1 = a[0] + a[1][a[1].length() - 1];
    p2 = a[1] + a[0][a[0].length() - 1];
    string p;
    char ans[205];
    ans[m] = '\0';
    if (is_suffix(a[1], p1)) {
        p = p1;
        bool bisa = true;
        for (int i = 0; i < m; i++) {
            int l = s[i].length();
            if (is_prefix(s[i], p)) {
                if (sudah[l] != -1) {
                    if (is_suffix(s[i], p)) {
                        ans[i] = 'S';
                        ans[sudah[l]] = 'P';
                    } else if (is_suffix(s[sudah[l]], p)) {
                        ans[sudah[l]] = 'S';
                        ans[i] = 'P';
                    } else {
                        bisa = false;
                    }
                } else {
                    ans[i] = 'P';
                    sudah[l] = i;
                }
            } else if(is_suffix(s[i], p)) {
                ans[i] = 'S';
            } else {
                bisa = false;
            }
        }
        if (bisa) {
            printf("%s", ans);
            return 0;
        }
    }
    if (is_suffix(a[0], p2)) {
        p = p2;
        bool bisa = true;
        for (int i = 0; i < m; i++) {
            int l = s[i].length();
            if (is_prefix(s[i], p)) {
                if (sudah[l] != -1) {
                    if (is_suffix(s[i], p)) {
                        ans[i] = 'S';
                        ans[sudah[l]] = 'P';
                    } else if (is_suffix(s[sudah[l]], p)) {
                        ans[sudah[l]] = 'S';
                        ans[i] = 'P';
                    } else {
                        bisa = false;
                    }
                } else {
                    ans[i] = 'P';
                    sudah[l] = i;
                }
            } else if(is_suffix(s[i], p)) {
                ans[i] = 'S';
            } else {
                bisa = false;
            }
        }
        if (bisa) {
            printf("%s", ans);
            return 0;
        }
    }
    return -1;

}
