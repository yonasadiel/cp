#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pii pair<int, int>
#define mp make_pair
using namespace std;

int n, k;
int a[1000005], b[1000005], c[1000005];

void debug(const set<pii>& s) {
    auto it = s.begin();
    while (it != s.end()) {
        printf("(%d, %d) ", it->first, it->second);
        it++;
    }
    printf("\n");
}

void process(int* arr, int& med) {
    set<pii> s;
    for (int i = 0; i < k; i++) {
        s.insert(mp(arr[i], i));
    }
    auto medi = s.begin();
    for (int i = 0; i < ( k / 2 ); i++) {
        medi++;
    }
    
    med = medi->fi;

    // printf("medi = %d, %d ", medi->fi, medi->se); debug(s);
    for (int r = k, l = 0; r < n; r++, l++) {
        pii pl = mp(arr[l], l);
        pii pr = mp(arr[r], r);
        pii pm = mp(medi->fi, medi->se);
        bool dihapus = false;
        if (medi->se == l) {
            medi++;
            dihapus = true;
        }
        s.erase(pl);
        s.insert(pr);

        if (pl < pm && pm < pr) {
            medi++;
        } else if (pr < pm && pm <= pl) {
            medi--;
        } else if (dihapus && pm < pr && pr < *medi) {
            medi--;
        }
        // printf("medi = %d, %d ", medi->fi, medi->se); debug(s);

        med = max(medi->fi, med);
    }
}

int main() {
    scanf("%d%d", &n, &k);

    for (int i=0; i<n; i++) scanf("%d", &a[i]);
    for (int i=0; i<n; i++) scanf("%d", &b[i]);
    for (int i=0; i<n; i++) scanf("%d", &c[i]);

    int med_a, med_b, med_c;
    if (k == 1) {
        med_a = a[0];
        med_b = b[0];
        med_c = c[0];
        for (int i=1; i<n; i++) {
            med_a = max(a[i], med_a);
            med_b = max(b[i], med_b);
            med_c = max(c[i], med_c);
        }
    } else {
        process(a, med_a);
        process(b, med_b);
        process(c, med_c);
    }
    // fprintf(stderr, "%d %d %d\n", med_a, med_b, med_c);

    int arr[] = {med_a, med_b, med_c};
    sort(arr, arr + 3);
    printf("%d\n", arr[1]);
}
