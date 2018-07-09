#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

bool pet[500][500];

void exec(int tc) {
    int n;
    scanf("%d", &n);
    memset(pet, false, sizeof pet);

    int width = 3;
    for (; n%width != 0; width++);
    int height = max(3, n / width);

    int cr = 2;
    int cc = 2;
    int take = 0;
    while (take < width*height) {
        if (!pet[cr][cc]) {
            int gr = min(cr+1, 2+height-2), ar;
            int gc = min(cc+1, 2+width-2), ac;
            printf("%d %d\n", gr, gc);
            cout << flush;
            scanf("%d%d", &ar, &ac);
            if (ar == 0 && ac == 0) break;
            pet[ar][ac] = true;
        } else {
            take++;
            cc++;
            if (cc == 2+width) {
                cc = 2;
                cr++;
            }
        }
    }
}

int main() {
    int t;
    scanf("%d", &t);
    for (int i=1; i<=t; i++){
        exec(i);
    }
}