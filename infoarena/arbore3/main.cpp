#include <fstream>
#include <iostream>
#include <vector>
#define MAXN 1000010
#define MOD 666013
using namespace std;
ifstream f("arbore3.in");
ofstream g("arbore3.out");
vector<int> G[MAXN];
vector<int> H[2 * MOD];
int n, s, x, y, sc, v[MAXN];
long long nr;
void caut(int val) {
  int k = val % MOD + MOD;
  if (H[k].size() == 0)
    return;
  for (auto it : H[k])
    if (it == val)
      ++nr;
}
void dfs(int nod) {
  sc += v[nod];
  caut(sc - s);
  int k = sc % MOD + MOD;
  H[k].push_back(sc);
  for (auto it : G[nod])
    dfs(it);
  for (auto &it : H[k])
    if (it == sc) {
      it = H[k].back();
      H[k].pop_back();
      break;
    }
  sc -= v[nod];
}
int main() {
  f >> n >> s;
  for (int i = 1; i <= n; ++i) {
    f >> x >> v[i];
    G[x].push_back(i);
  }
  H[MOD].push_back(0);
  dfs(1);
  g << nr;
  return 0;
}
