#include <bitset>
#include <fstream>
#include <iostream>
#include <vector>
#define MAXN 130
using namespace std;
ifstream f("revolutie.in");
ofstream g("revolutie.out");
vector<int> G[MAXN];
vector<pair<int, int>> v;
bitset<MAXN> viz;
int n, x, l[MAXN], r[MAXN], ok, nr, nrmut, aux;
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
  f >> n;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) {
      f >> x;
      if (x)
        G[i].push_back(j);
    }
  do {
    ok = 0;
    viz.reset();
    for (int i = 1; i <= n; i++)
      if (!l[i] && match(i)) {
        nr++;
        ok = 1;
      }
  } while (ok);
  if (nr < n) {
    g << -1;
    return 0;
  }
  for (int i = 1; i <= n; i++)
    if (l[i] != i) {
      nrmut++;
      v.push_back(make_pair(i, l[i]));
      aux = l[i];
      l[r[i]] = l[i];
      r[aux] = r[i];
    }
  g << nrmut << '\n';
  for (auto it : v)
    g << 'C' << ' ' << it.first << ' ' << it.second << '\n';
  return 0;
}
