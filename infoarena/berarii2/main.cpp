#include <fstream>
#include <iostream>
#include <vector>
using namespace std;
#define MAXN 1000010
ifstream f("berarii2.in");
ofstream g("berarii2.out");
vector<int> G[MAXN], w;
int v[MAXN], viz[MAXN], n, m, x, y, p, k;
void dfs(int nod) {
  viz[nod] = 1;
  for (auto it : G[nod]) {
    if (!viz[it])
      dfs(it);
    if (v[it] == 1)
      v[nod] = 1;
  }
}
int main() {
  f >> n >> m >> p;
  while (m--) {
    f >> x >> y;
    G[y].push_back(x);
  }
  while (p--) {
    f >> x;
    dfs(x);
  }
  for (int i = 1; i <= n; i++)
    if (viz[i] == 0) {
      k++;
      w.push_back(i);
    }
  g << k << '\n';
  for (auto it : w)
    g << it << '\n';
  return 0;
}
