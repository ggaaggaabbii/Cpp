#include <fstream>
#include <iostream>
#include <vector>
using namespace std;
ifstream f("atac.in");
ofstream g("atac.out");
#define MAXN 32010
#define MAXLOG 18
#define INF 1000000000
vector<int> G[MAXN];
int n, m, p, niv[MAXN], x, y, str[MAXLOG][MAXN], dp[MAXLOG][MAXN], a, b, c, d,
    z;
void dfs(int nod) {
  for (auto it : G[nod]) {
    niv[it] = niv[nod] + 1;
    dfs(it);
  }
}
int get_min(int x, int y) {
  if (niv[x] < niv[y])
    swap(x, y);
  int minim = INF;
  int dif = niv[x] - niv[y];
  for (int k = 0; (1 << k) <= dif; k++)
    if (dif & (1 << k)) {
      minim = min(minim, dp[k][x]);
      x = str[k][x];
    }
  for (int k = MAXLOG - 1; k >= 0; k--) {
    if (str[k][x] != str[k][y]) {
      minim = min(minim, dp[k][x]);
      x = str[k][x];
      minim = min(minim, dp[k][y]);
      y = str[k][y];
    }
  }
  if (x != y)
    minim = min(minim, min(dp[0][x], dp[0][y]));
  if (minim == INF)
    return 0;
  return minim;
}
int main() {
  f >> n >> m >> p;
  for (int i = 2; i <= n; i++) {
    f >> x >> y;
    G[x].push_back(i);
    str[0][i] = x;
    dp[0][i] = y;
  }
  dfs(1);
  for (int k = 1; k < MAXLOG; k++) {
    for (int i = 1; i <= n; i++) {
      str[k][i] = str[k - 1][str[k - 1][i]];
      dp[k][i] = min(dp[k - 1][i], dp[k - 1][str[k - 1][i]]);
    }
  }
  f >> x >> y >> a >> b >> c >> d;
  for (int i = 1; i <= m; i++) {
    z = get_min(x, y);
    if (m - i + 1 <= p)
      g << z << '\n';
    x = (x * a + b * y) % n + 1;
    y = (y * c + z * d) % n + 1;
  }
  return 0;
}
