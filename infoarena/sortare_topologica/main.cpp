#include <fstream>
#include <iostream>
#include <vector>
using namespace std;
#define MAXN 50010
ifstream f("sortaret.in");
ofstream g("sortaret.out");
vector<int> G[MAXN];
int v[MAXN], viz[MAXN], n, m, x, y, k;
void df(int nod) {
  viz[nod]++;
  int nr = G[nod].size();
  for (int i = 0; i < nr; i++)
    if (!viz[G[nod][i]])
      df(G[nod][i]);
  v[++k] = nod;
}
int main() {
  f >> n >> m;
  while (m--) {
    f >> x >> y;
    G[x].push_back(y);
  }
  for (int i = 1; i <= n; i++) {
    if (!viz[i])
      df(i);
  }
  for (int i = n; i >= 1; i--)
    g << v[i] << ' ';
  return 0;
}
