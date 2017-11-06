#include <fstream>
#include <iostream>
#include <vector>
using namespace std;
#define MAXN 16010
vector<int> G[MAXN];
ifstream f("sediu.in");
ofstream g("sediu.out");
int viz[MAXN], weight[MAXN], optim[MAXN], k, n, v[MAXN], x, y;
void dfs(int nod) {
  viz[nod] = 1;
  int maxim = 0;
  for (int i = 0; i < G[nod].size(); i++) {
    if (!viz[G[nod][i]]) {
      dfs(G[nod][i]);
      weight[nod] += weight[G[nod][i]];
      maxim = max(maxim, weight[G[nod][i]]);
    }
  }
  maxim = max(maxim, n - weight[nod]);
  optim[nod] = maxim;
}
int main() {
  f >> n;
  int minim = 99999;
  for (int i = 1; i < n; i++) {
    f >> x >> y;
    G[x].push_back(y);
    G[y].push_back(x);
  }
  for (int i = 1; i <= n; i++) {
    weight[i] = 1;
  }
  for (int i = 1; i <= n; i++) {
    if (!viz[i])
      dfs(i);
  }
  for (int i = 1; i <= n; i++) {
    minim = min(minim, optim[i]);
  }
  g << minim << ' ';
  for (int i = 1; i <= n; i++) {
    if (optim[i] == minim) {
      v[++k] = i;
    }
  }
  g << k << '\n';
  for (int i = 1; i <= k; i++)
    g << v[i] << ' ';
  return 0;
}
