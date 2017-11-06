#include <fstream>
#include <iostream>
#include <vector>
using namespace std;
#define MAXN 100010
ifstream f("dfs.in");
ofstream g("dfs.out");
vector<int> G[MAXN];
int viz[MAXN], n, m, nr, x, y;
void df(int nod) {
  viz[nod] = 1;
  for (int i = 0; i < G[nod].size(); i++)
    if (!viz[G[nod][i]])
      df(G[nod][i]);
}
int main() {
  f >> n >> m;
  while (m--) {
    f >> x >> y;
    G[x].push_back(y);
    G[y].push_back(x);
  }
  for (int i = 1; i <= n; i++) {
    if (!viz[i]) {
      df(i);
      nr++;
    }
  }
  g << nr;
  return 0;
}
