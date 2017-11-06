#include <fstream>
#include <iostream>
#include <vector>
using namespace std;
#define MAXN 1000010
ifstream f("darb.in");
ofstream g("darb.out");
vector<int> G[MAXN];
int viz[MAXN], dist[MAXN], n, x, y, maxim, nod1;
void dfs(int nod) {
  viz[nod] = 1;
  for (int i = 0; i < G[nod].size(); i++) {
    if (!viz[G[nod][i]]) {
      dist[G[nod][i]] = dist[nod] + 1;
      if (dist[G[nod][i]] > maxim) {
        maxim = dist[G[nod][i]];
        nod1 = G[nod][i];
      }
      dfs(G[nod][i]);
    }
  }
}
int main() {
  f >> n;
  for (int i = 1; i < n; i++) {
    f >> x >> y;
    G[x].push_back(y);
    G[y].push_back(x);
  }
  dfs(1);
  for (int i = 1; i <= n; i++) {
    dist[i] = 0;
    viz[i] = 0;
  }
  dfs(nod1);
  g << maxim + 1;
  return 0;
}
