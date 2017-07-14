#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
#include <cstring>
#define pii pair<int,int>
#define piiii pair<pii, pii>
#define x first.first
#define type first.second
#define y_1 second.first
#define y_2 second.second
#define mp make_pair
using namespace std;

// which one to be processed first must be lower value
const int left_point = 0;
const int vertical_line = 1;
const int right_point = 2;

int n;
int a,b,c,d;
vector<piiii> v;

vector<int> to_be_segtree;
int segtree[600005];

int segtree_operation(int a, int b) {
  // return the operation. change to addition, minimize, or maximize
  return a+b;
}

void segtree_build(int node, int le, int ri) {
  if (le == ri) { segtree[node] = to_be_segtree[le]; }
  else {
    int node_left  = (node << 1);
    int node_right = (node << 1) + 1;
    int mi         = ((le+ri) >> 1);

    segtree_build(node_left , le,   mi);
    segtree_build(node_right, mi+1, ri);

    segtree[node] = segtree_operation(segtree[node_left], segtree[node_right]);
  }
}

int segtree_range_query(int node, int le, int ri, int q_le, int q_ri) {
  if (le >  q_ri || ri <  q_le) return -1;
  if (le >= q_le && ri <= q_ri) return segtree[node];

  int node_left  = (node << 1);
  int node_right = (node << 1) + 1;
  int mi = (le+ri) >> 1;

  int exec_left  = segtree_range_query(node_left , le,   mi, q_le, q_ri);
  int exec_right = segtree_range_query(node_right, mi+1, ri, q_le, q_ri);

  if (exec_left  == -1) return exec_right;
  if (exec_right == -1) return exec_left;
  return segtree_operation(exec_left, exec_right);
}

void segtree_update(int node, int le, int ri, int pos, int val) {
  if (le == ri) { segtree[node] = val; return; }

  int node_left  = (node << 1);
  int node_right = (node << 1) + 1;
  int mi = (le+ri) >> 1;

  if (pos <= mi) { segtree_update(node_left , le  , mi, pos, val); }
  else           { segtree_update(node_right, mi+1, ri, pos, val); }

  segtree[node] = segtree_operation(segtree[node_left], segtree[node_right]);
}

int main() {
  scanf("%d",&n);
  for (int i=0; i<n; i++) {
    scanf("%d%d%d%d",&a, &b, &c, &d);
    if (b == d) {
      v.push_back(mp(mp(a, 0), mp(b, d)));
      v.push_back(mp(mp(c, 2), mp(b, d)));
    } else {
      v.push_back(mp(mp(a, 1), mp(b, d)));
    }
    
  }

  sort(v.begin(), v.end());

  memset(segtree, 0, sizeof segtree);

  long long ret = 0;
  for (int i=0; i<v.size(); i++) {
    if (v[i].type == left_point) {
      segtree_update(1, 0, 100005, v[i].y_1, 1);
    } else if (v[i].type == vertical_line) {
      ret += segtree_range_query(1, 0, 100005, v[i].y_1, v[i].y_2);
    } else {
      segtree_update(1, 0, 100005, v[i].y_1, 0);
    }
  }

  printf("%lld\n",ret);
}