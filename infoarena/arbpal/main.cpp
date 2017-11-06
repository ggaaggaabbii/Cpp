#include <bitset>
#include <fstream>
#include <iostream>
#include <vector>
#define MAXN 5010
#define MOD 666013
#define MOD2 100007
using namespace std;
ifstream f("arbpal.in");
ofstream g("arbpal.out");
bitset<MAXN> ok[MAXN];
vector<int> G[MAXN];
int nr, x, y, viz[MAXN], n;
char c[MAXN];
void dfs(int nod1, int nod2) {
  for (auto it : G[nod1])
    if (!viz[it]) {
      viz[it] = 1;
      for (auto it2 : G[nod2])
        if (c[it] == c[it2] && !viz[it2]) {
          viz[it2] = 1;
          if (!ok[it][it2]) {
            nr += 2;
            ok[it][it2] = 1;
            ok[it2][it] = 1;
            dfs(it, it2);
          }
          viz[it2] = 0;
        }
      viz[it] = 0;
    }
}
int main() {
  f >> n;
  for (int i = 1; i < n; ++i) {
    f >> x >> y;
    G[x].push_back(y);
    G[y].push_back(x);
  }
  for (int i = 1; i <= n; ++i)
    f >> c[i];
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j)
      viz[j] = 0;
    viz[i] = 1;
    dfs(i, i);
    for (auto it : G[i]) {
      viz[i] = viz[it] = 1;
      if (c[it] == c[i] && it > i) {
        nr += 2;
        ok[i][it] = ok[it][i] = 1;
        dfs(i, it);
      }
      viz[i] = viz[it] = 0;
    }
  }
  g << nr + n;
  return 0;
}
