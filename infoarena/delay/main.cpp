#include <fstream>
#include <iostream>
#include <vector>
using namespace std;
#define MAXN 16010
ifstream f("delay.in");
ofstream g("delay.out");
vector<int> G[MAXN];
int d[2 * MAXN], pi[MAXN], pf[MAXN], t[MAXN], niv[MAXN], viz[MAXN],
    str[20][MAXN], arb[8 * MAXN];
int poz, x, y, n, m, c, o;
void dfs(int nod) {
  viz[nod] = 1;
  d[++poz] = t[nod];
  pi[nod] = poz;
  for (auto it : G[nod])
    if (!viz[it]) {
      niv[it] = niv[nod] + 1;
      str[0][it] = nod;
      dfs(it);
    }
  d[++poz] = -t[nod];
  pf[nod] = poz;
}
void build(int nod, int st, int dr) {
  if (st == dr) {
    arb[nod] = d[st];
    return;
  }
  int mij = (st + dr) / 2;
  build(2 * nod, st, mij);
  build(2 * nod + 1, mij + 1, dr);
  arb[nod] = arb[2 * nod] + arb[2 * nod + 1];
}
void update(int nod, int st, int dr, int poz, int val) {
  if (st == dr) {
    arb[nod] = val;
    return;
  }
  int mij = (st + dr) / 2;
  if (poz <= mij)
    update(2 * nod, st, mij, poz, val);
  else
    update(2 * nod + 1, mij + 1, dr, poz, val);
  arb[nod] = arb[2 * nod] + arb[2 * nod + 1];
}
int get_lca(int x, int y) {
  if (niv[x] < niv[y])
    swap(x, y);
  for (int k = 18; k >= 0; k--)
    if (niv[str[k][x]] >= niv[y])
      x = str[k][x];
  if (x == y)
    return x;
  for (int k = 18; k >= 0; k--)
    if (str[k][x] && str[k][x] != str[k][y]) {
      x = str[k][x];
      y = str[k][y];
    }
  return str[0][x];
}
int query(int nod, int st, int dr, int x, int y) {
  if (x <= st && y >= dr)
    return arb[nod];
  int mij = (st + dr) / 2;
  if (y <= mij)
    return query(2 * nod, st, mij, x, y);
  if (x > mij)
    return query(2 * nod + 1, mij + 1, dr, x, y);
  return query(2 * nod, st, mij, x, y) + query(2 * nod + 1, mij + 1, dr, x, y);
}
int main() {
  f >> n;
  for (int i = 1; i <= n; i++)
    f >> t[i];
  for (int i = 1; i < n; i++) {
    f >> x >> y;
    G[x].push_back(y);
    G[y].push_back(x);
  }
  niv[1] = 1;
  dfs(1);
  for (int i = 1; (1 << i) <= n; i++)
    for (int j = 1; j <= n; j++)
      str[i][j] = str[i - 1][str[i - 1][j]];
  build(1, 1, 2 * n);
  f >> m;
  while (m--) {
    f >> o >> x >> y;
    if (o == 2) {
      c = get_lca(x, y);
      g << query(1, 1, 2 * n, min(pi[x], pi[c]), max(pi[x], pi[c])) +
               query(1, 1, 2 * n, min(pi[y], pi[c]), max(pi[y], pi[c])) - t[c]
        << '\n';
    } else {
      update(1, 1, 2 * n, pi[x], y);
      update(1, 1, 2 * n, pf[x], -y);
      t[x] = y;
    }
  }
  return 0;
}
