#include <fstream>
#include <iostream>
#include <vector>
using namespace std;
#define MAXN 100010
ifstream f("maimute.in");
ofstream g("maimute.out");
vector<int> G[MAXN];
int pi[MAXN], pf[MAXN], n, m, x, y, k, viz[MAXN];
void dfs(int nod) {
  viz[nod] = 1;
  pi[nod] = ++k;
  for (auto it : G[nod])
    if (!viz[it])
      dfs(it);
  pf[nod] = ++k;
}
int main() {
  f >> n;
  for (int i = 1; i < n; i++) {
    f >> x >> y;
    G[x].push_back(y);
    G[y].push_back(x);
  }
  dfs(1);
  f >> m;
  while (m--) {
    f >> x >> y;
    if ((pi[x] < pi[y] && pf[x] > pf[y]) || (pi[y] < pi[x] && pf[y] > pf[x]))
      g << "DA\n";
    else
      g << "NU\n";
  }
  return 0;
}
