#include <bits/stdc++.h>
using namespace std;

int k;
char a[200005];
char b[200005];

void inc(char* s, int pos) {
    if (s[pos] == 'z') {
        s[pos] = 'a';
        inc(s, pos - 1);
    } else {
        s[pos]++;
    }
}

void dec(char* s, int pos) {
    if (s[pos] == 'a') {
        s[pos] = 'z';
        dec(s, pos - 1);
    } else {
        s[pos]--;
    }
}

int main() {
    scanf("%d", &k);
    scanf("%s", a);
    scanf("%s", b);

    int selisih = 0;
    for (int i = 0; i < k; i++) {
        selisih *= 26;
        selisih += b[i] - a[i];

        if (selisih < 0) {
            inc(b, i - 1);
            dec(a, i - 1);
            selisih += 52;
        }

        while (selisih > 1) {
            dec(b, i);
            inc(a, i);
            selisih -= 2;
        }
    }
    printf("%s\n", a);
}
