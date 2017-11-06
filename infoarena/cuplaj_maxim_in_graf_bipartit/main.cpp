#include <bitset>
#include <fstream>
#include <iostream>
#include <vector>
#define MAXN 10010
using namespace std;
ifstream f("cuplaj.in");
ofstream g("cuplaj.out");
vector<int> G[MAXN];
bitset<MAXN> viz;
int l[MAXN], r[MAXN], n, m, ok, x, nr, y, k;
int match(int nod) {
  if (viz[nod])
    return 0;
  viz[nod] = 1;
  for (auto it : G[nod])
    if (!r[it]) {
      l[nod] = it;
      r[it] = nod;
      return 1;
    }
  for (auto it : G[nod])
    if (!viz[r[it]] && match(r[it])) {
      l[nod] = it;
      r[it] = nod;
      return 1;
    }
  return 0;
}
int main() {
  f >> n >> m >> k;
  while (k--) {
    f >> x >> y;
    G[x].push_back(y);
  }
  do {
    ok = 0;
    viz.reset();
    for (int i = 1; i <= n; ++i)
      if (!l[i] && match(i)) {
        ok = 1;
        nr++;
      }
  } while (ok);
  g << nr << '\n';
  for (int i = 1; i <= n; i++)
    if (l[i])
      g << i << ' ' << l[i] << '\n';
  return 0;
}
