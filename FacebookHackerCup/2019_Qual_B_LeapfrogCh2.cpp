#include <bits/stdc++.h>
using namespace std;

int n;
char cc[10000];

int main() {
    scanf("%d\n", &n);
    for (int tc=1; tc<=n; tc++) {
        scanf("%s\n", cc);
        int b = 0, c = 0;
        for (int i=1; i<strlen(cc); i++) {
            if (cc[i] == 'B') b++;
            else c++;
        }
        printf("Case #%d: %c\n", tc, ((b > 1 && c > 0) || (b == 1 && c == 1)) ? 'Y' : 'N');
    }
}
