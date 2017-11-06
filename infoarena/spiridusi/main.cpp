#include <fstream>
#include <iostream>
#include <vector>
#define MAXN 100010
#define MAXLOG 20
#define INF 1000000000
using namespace std;
ifstream f("spiridusi.in");
ofstream g("spiridusi.out");
int stra[MAXLOG][MAXN], sump[MAXLOG][MAXN], sp[MAXN], x, s[MAXN], c, n, y,
    niv[MAXN], maxim = -INF;
vector<int> G[MAXN];
void dfs(int nod, int dad) {
  niv[nod] = niv[dad] + 1;
  sp[nod] += sp[dad];
  stra[0][nod] = dad;
  sump[0][nod] = sp[nod];
  s[nod] += s[dad];
  for (auto it : G[nod])
    if (it != dad)
      dfs(it, nod);
}
void solve(int nod, int dad) {
  int stramos = nod, lung, minim = INF, stra2 = dad;
  for (int k = MAXLOG - 1; k >= 0; --k)
    if (stra[k][stramos] && s[nod] - s[stra[0][stra[k][stramos]]] <= c)
      stramos = stra[k][stramos];
  lung = niv[nod] - niv[stramos] + 1;
  for (int k = MAXLOG - 1; k >= 0; --k)
    if (((1 << k) & lung) != 0) {
      minim = min(minim, sump[k][stra2]);
      stra2 = stra[k][stra2];
    }
  maxim = max(maxim, sp[nod] - minim);
  for (auto it : G[nod])
    if (it != dad)
      solve(it, nod);
}
int main() {
  f >> n >> c;
  for (int i = 1; i <= n; ++i)
    f >> s[i];
  for (int i = 1; i <= n; ++i)
    f >> sp[i];
  for (int i = 1; i < n; ++i) {
    f >> x >> y;
    G[x].push_back(y);
    G[y].push_back(x);
  }
  dfs(1, 0);
  for (int k = 1; (1 << k) <= n; ++k)
    for (int i = 1; i <= n; ++i)
      stra[k][i] = stra[k - 1][stra[k - 1][i]];
  for (int k = 1; (1 << k) <= n; ++k)
    for (int i = 1; i <= n; ++i)
      sump[k][i] = min(sump[k - 1][i], sump[k - 1][stra[k - 1][i]]);
  solve(1, 0);
  g << maxim;
  return 0;
}
