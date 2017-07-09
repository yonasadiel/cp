/**
 * The Order of Function Inlining
 * TL: 1s
 * Given N functions and each prerequisite functions.
 * Create the order of execution of the functions.
 * Constraints:
 *   1 <= N <= 1000
 */

#include <cstdio>
#include <map>
#include <vector>
#include <queue>
#include <utility>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int n,k;
string s;
vector<int> prnt[1005];
vector<int> chld[1005];
int cntchld[1005];
int cntprnt[1005];
map<string, int> matoint;
map<int, string> matostr;
bool takn[1005];
vector<int> ans;

int masize = 0;

void savema(string s) {
  matoint[s] = masize;
  matostr[masize] = s;
  masize++;
}

int toindex(string s) {
  if (matoint.count(s) == 0) {
    savema(s);
  }
  return matoint[s];
}

string tofunc(int i) {
  return matostr[i];
}

bool isleaf(int i) {
  return cntchld[i] == 0;
}

bool cmp(int le, int ri) {
  return cntprnt[le] > cntprnt[ri];
}

void topo() {
  priority_queue<pair<string,int> , vector<pair<string,int> >, greater<pair<string,int> > > pq;

  for (int i=0; i<n; i++) {
    if (isleaf(i)) {
      pq.push(make_pair(tofunc(i), i));
    }
  }

  while (!pq.empty()) {
    int cur = pq.top().second;
    //printf("DEBUG : %d %d\n",pq.top().first, pq.top().second);
    pq.pop();

    takn[cur] = true;
    ans.push_back(cur);

    for (int i=0; i<prnt[cur].size(); i++) {
      int next = prnt[cur][i];
      cntchld[next]--;
      if (!takn[next] && isleaf(next)) {
        pq.push(make_pair(tofunc(next),next));
      }
    }
  }

  for (int i=0; i<n; i++) {
    if (i != n-1) {
      cout<<tofunc(ans[i])<<" -> ";
    } else {
      cout<<tofunc(ans[i])<<endl;
    }
  }
}

int main() {
  memset(takn, false, sizeof takn);
  memset(cntchld, 0, sizeof cntchld);
  scanf("%d",&n);
  for (int i=0; i<n; i++) {
    cin>>s;
    int ayah = toindex(s);

    scanf("%d",&k);
    for (int j=0; j<k; j++) {
      cin>>s;
      int anak = toindex(s);
      prnt[anak].push_back(ayah);
      chld[ayah].push_back(anak);
      cntchld[ayah]++;
      cntprnt[anak]++;
    }
  }

  topo();
}