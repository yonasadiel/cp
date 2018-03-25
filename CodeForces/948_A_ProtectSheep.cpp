#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <stack>
#include <map>
#include <set>
#define ll long long
#define pb push_back
#define fi first
#define se second
#define mp make_pair
#define vi vector<int>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pdd pair<double,double>
#define DEBUG if (debug)
using namespace std;

const bool debug = true;

void dump(int x) { fprintf(stderr, "%d", x); }
void dump(char x) { fprintf(stderr, "%c", x); }
void dump(char* x) { fprintf(stderr, "%s", x); }
void dump(ll x) { fprintf(stderr, "%I64d", x); }
void dump(float x) { fprintf(stderr, "%.5f", x); }
void dump(double x) { fprintf(stderr, "%.5lf", x); }
void dump(string x) { cerr << x; }
template<class T> void dump(T* x, int n) { dump('['); for (int i=0; i<n; i++) { if (i>0) dump(','); dump(x[i]); } dump(']'); }
template<class T> void dump(vector<T> x) { dump('<'); for (int i=0; i<x.size(); i++) { if (i>0) dump(','); dump(x[i]); } dump('>'); }
template<class T1, class T2> void dump(pair<T1, T2> x) { dump('('); dump(x.fi); dump(','); dump(x.se); dump(')'); }

void dumpln() { fprintf(stderr, "\n"); }
template<class T> void dumpln(T* x, int n) { dump(x, n); dump('\n'); }
template<class T> void dumpln(T x) { dump(x); dumpln(); }

int r,c;
char pet[505][505];
const int DIRECTION = 4;
int dr[] = {0, 1, 0, -1};
int dc[] = {1, 0, -1, 0};
bool valid(int rn, int cn) {
    return rn >= 0 && cn >= 0 && rn < r && cn < c;
}

int main() {
    scanf("%d%d\n",&r,&c);
    for (int i=0; i<r; i++) {
        for (int j=0; j<c; j++) {
            scanf("%c",&pet[i][j]);
        }
        scanf("\n");
    }

    bool aman = true;
    for (int i=0; i<r; i++) {
        for (int j=0; j<c; j++) {
            if (pet[i][j] == 'S')
            for (int k=0; k<DIRECTION; k++) {
                int rn = i + dr[k];
                int cn = j + dc[k];
                if (valid(rn,cn)) {
                    if (pet[rn][cn] == 'W') { aman = false; }
                }
            }
        }
    }
    if (aman) {
        printf("Yes\n");
        for (int i=0; i<r; i++) {
            for (int j=0; j<c; j++) {
                if (pet[i][j] == '.') { printf("D"); }
                else { printf("%c", pet[i][j]); }
            }
            printf("\n");
        }
    } else {
        printf("No\n");
    }
}
