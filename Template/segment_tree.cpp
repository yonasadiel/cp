#include <cstdio>
#include <vector>
using namespace std;

vector<int> to_be_segtree;
int segtree[500005];

int segtree_operation(int a, int b) {
  // return the operation. change to addition, minimize, or maximize
  return (a<b)? a : b;
}

void segtree_build(int node, int le, int ri) {
  if (le == ri) { segtree[node] = to_be_segtree[le]; }
  else {
    int node_left  = (node << 1);
    int node_right = (node << 1) + 1;
    int mi         = ((le+ri) >> 1);
    segtree_build(node_left , le,   mi); // build left
    segtree_build(node_right, mi+1, ri); // build right
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

int main() {
  int arr[] = {4, 3, 7, 9, 5, 1};

  for (int i=0; i<6; i++) { to_be_segtree.push_back(arr[i]); }

  segtree_build(1, 0, to_be_segtree.size()-1);

  while (true) {
    int a,b;
    scanf("%d%d",&a,&b);
    printf("%d\n",segtree_range_query(1, 0, to_be_segtree.size()-1, a,b));
  }
}