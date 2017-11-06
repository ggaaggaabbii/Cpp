#include <fstream>
#include <iostream>
#include <vector>
using namespace std;
#define MAXN 16010
ifstream f("asmax.in");
ofstream g("asmax.out");
vector<int> G[MAXN];
int maxim, v[MAXN], viz[MAXN], n, x, y;
void dfs(int nod) {
  viz[nod] = 1;
  for (auto it : G[nod]) {
    if (!viz[it]) {
      dfs(it);
      if (v[it] > 0) {
        v[nod] += v[it];
      }
    }
  }
}
int main() {
  f >> n;
  for (int i = 1; i <= n; i++)
    f >> v[i];
  for (int i = 1; i < n; i++) {
    f >> x >> y;
    G[x].push_back(y);
    G[y].push_back(x);
  }
  dfs(1);
  maxim = v[1];
  for (int i = 2; i <= n; i++) {
    maxim = max(maxim, v[i]);
  }
  g << maxim;
  return 0;
}
