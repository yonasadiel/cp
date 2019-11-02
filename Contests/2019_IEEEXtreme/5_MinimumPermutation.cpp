#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define INF 2000000000000000000LL
#define EPS 1e-9
#define debug(a) cerr<<#a<<"="<<(a)<<"\n"
#define debug2(a, b) cerr<<#a<<"="<<(a)<<" ";debug(b)
#define debug3(a, b, c) cerr<<#a<<"="<<(a)<<" ";debug2(b, c)
#define debug4(a, b, c, d) cerr<<#a<<"="<<(a)<<" ";debug3(b, c, d)
#define debug5(a, b, c, d, e) cerr<<#a<<"="<<(a)<<" ";debug4(b, c, d, e)
#define FastSlowInput ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long long ll;
typedef unsigned long long ull;
typedef complex<double> cd;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

template<class T>
void printArray(const T * a, int n, ostream& out = cerr);
template<class T>
void printArray(const vector<T> &arr, ostream& out = cerr);

const ll mod = 1e9+7;
const double PI = acos(-1);

template<class T>
struct mapper{
   std::vector<T> m;
   mapper(){}
   mapper(const T *arr, int sz){mapping(arr, sz);}
   mapper(const vector<T> &arr){mapping(arr);}
   void mapping(const T *arr, int sz){
       m.clear();
       for(int i=0;i<sz;++i)
           m.pb(arr[i]);
       sort(m.begin(), m.end());
       m.erase(unique(m.begin(), m.end()), m.end());
   }
   void mapping(const vector<T> &arr){
       m.clear();
       for(const T &x : arr)
           m.pb(x);
       sort(m.begin(), m.end());
       m.erase(unique(m.begin(), m.end()), m.end());
   }
   int get(const T &val){ return lower_bound(m.begin(), m.end(), val) - m.begin();}
   int operator[] (const T &val){ return get(val);}
};

int n,i,j,k,t;
int m;
int a[100002];
int b[100002];
int gpos[200002];
set<pii> s;
vector<int> v;
vector<pii> ans;
mapper<int> mep;
int tree[800008];

void build(int l, int r, int pos){
    if(l == r){
        tree[pos] = gpos[l];
        return;
    }
    int mid = (l+r)/2;
    build(l, mid, 2*pos+1);
    build(mid+1, r, 2*pos+2);
    tree[pos] = min(tree[2*pos+1], tree[2*pos+2]);
}
int ql, qr;
int query(int l, int r, int pos){
    if(l>qr || r<ql) return n;
    if(l>=ql && r <= qr) return tree[pos];
    int mid = (l+r)/2;
    return min(query(l, mid, 2*pos+1), query(mid+1, r, 2*pos+2));
}

int main(){
    scanf("%d %d", &n, &m);
    for(int i=0;i<n;++i){
        scanf("%d", a+i);
        v.pb(a[i]);
    }
    for(int i=0;i<m;++i){
        scanf("%d", b+i);
        v.pb(b[i]);
    }
    mep.mapping(v);
    for(int i=0;i<200000;++i)
        gpos[i] = n;
    for(int i=n-1;i>=0;--i){
        a[i] = mep[a[i]];
        ans.pb({i, a[i]});
        gpos[a[i]] = i;
    }
    qr = 199999;
    build(0, 199999, 0);
    for(int i = 0;i<m;++i){
        b[i] = mep[b[i]];
        ql = b[i];
        int pos = query(0, 199999, 0);
        ans.pb({pos, b[i]});
    }
    sort(ans.begin(), ans.end());
    for(const pii & x : ans){
        printf("%d ", mep.m[x.se]);
    }
    puts("");
    return 0;
}

/* Template Function */
template<class T>
void printArray(const T * a, int n, ostream& out){
    for(int i=0;i<n;++i){
        out<<a[i]<<" ";
    }
    out<<endl;
}

template<class T>
void printArray(const vector<T> &arr, ostream& out){
    for(const T& x : arr){
        out<<x<<" ";
    }
    out<<endl;
}