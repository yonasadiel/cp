/**
 * AncamanAlien
 * TL: 1s
 * LCA with RMQ on Segment Tree
 * TLE on naive LCA
 * RTE when segment tree arr < 600k
 * Constraints:
 *   1 <= N <= 100 000
 *   1 <= Q <= 50 000
 */

#include <cstdio>
#include <vector>
using namespace std;

/*********** SEGMENT TREE SECTION ************/

vector<int> to_be_segtree;
int segtree[600005];

int segtree_operation(int a, int b) {
  // return the operation. change to addition, minimize, or maximize
  return (a<b)? a : b;
}

void segtree_build(int node, int le, int ri) {
  if (le == ri) { segtree[node] = le; }
  else {
    int node_left  = (node << 1);
    int node_right = (node << 1) + 1;
    int mi         = ((le+ri) >> 1);
    segtree_build(node_left , le,   mi); // build left
    segtree_build(node_right, mi+1, ri); // build right
    segtree[node] = (to_be_segtree[segtree[node_left]] < to_be_segtree[segtree[node_right]])? segtree[node_left] : segtree[node_right];      // edited to return index
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
  return (to_be_segtree[exec_left] < to_be_segtree[exec_right])? exec_left : exec_right;      // edited to return index
}

/******************* LOWEST COMMON ANCESTOR SECTION ******************/

int n;
vector<int> adj[100005];
vector<int> euler_path;
int first_occ[100005];

void input_graph() {
  int a,b;
  scanf("%d",&n);
  for (int i=0; i<n-1; i++) {
    scanf("%d%d",&a,&b);
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
}

void make_euler_path(int pos, int parent, int level) {
  to_be_segtree.push_back(level);
  euler_path.push_back(pos);
  first_occ[pos] = euler_path.size()-1;

  for (int i=0; i<adj[pos].size(); i++) {
    int next = adj[pos][i];

    if (next != parent) {
      make_euler_path(next, pos, level+1);

      to_be_segtree.push_back(level);
      euler_path.push_back(pos);
    }
  }
}

int lca(int a, int b) {
  return euler_path[segtree_range_query(1, 0, to_be_segtree.size()-1, first_occ[a], first_occ[b])];
}

void process_query() {
  int q, qx, qy;
  scanf("%d",&q);
  for (int i=0; i<q; i++) {
    scanf("%d%d",&qx,&qy);
    if (lca(qx, qy) == qx) {
      printf("TIDAK\n");
    } else {
      printf("YA\n");
    }
  }
}

int main() {
  input_graph();

  int root = 1;
  make_euler_path(root, -1, 0);

  segtree_build(1, 0, to_be_segtree.size()-1);

  process_query();

}
