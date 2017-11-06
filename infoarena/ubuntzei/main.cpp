#include <bits/stdc++.h>
#define MAXN 2010
#define INF 1000000100
using namespace std;
ifstream f("ubuntzei.in");
ofstream g("ubuntzei.out");
vector<pair<int, int>> G[MAXN];
priority_queue<pair<int, int>> PQ;
int dist[17][MAXN], pr[MAXN], x, y, c, k, nod, stare, n, m, dst[MAXN],
    viz[MAXN], dp[(1 << 15) + 10][17], j, cost;
pair<int, int> aux;
void dij(int sursa, int *d) {
  while (PQ.size())
    PQ.pop();
  for (int i = 1; i <= n; i++) {
    d[i] = INF;
    viz[i] = 0;
  }
  d[sursa] = 0;
  PQ.push(make_pair(0, sursa));
  while (PQ.size()) {
    aux = PQ.top();
    PQ.pop();
    nod = aux.second;
    if (!viz[nod]) {
      viz[nod] = 1;
      for (auto it : G[nod]) {
        if (d[it.first] > d[nod] + it.second) {
          d[it.first] = d[nod] + it.second;
          PQ.push(make_pair(-d[it.first], it.first));
        }
      }
    }
  }
}
int main() {
  f >> n >> m >> k;
  for (int i = 1; i <= k; i++)
    f >> pr[i];
  while (m--) {
    f >> x >> y >> c;
    G[x].push_back(make_pair(y, c));
    G[y].push_back(make_pair(x, c));
  }
  dij(1, dst);
  if (k == 0) {
    g << dst[n];
    return 0;
  }
  for (int i = 1; i <= k; i++)
    dij(pr[i], dist[i]);
  for (int i = 1; i < (1 << k); ++i) {
    for (j = 0; j < k; ++j)
      if (i & (1 << j))
        break;
    if (j < k && i == (1 << j)) {
      dp[i][j] = dst[pr[j + 1]];
    } else
      for (j = 0; j < k; ++j) {
        dp[i][j] = INF;
        if (i & (1 << j)) {
          for (int p = 0; p < k; ++p) {
            if (j != p && i & (1 << p)) {
              cost = dp[i - (1 << j)][p] + dist[p + 1][pr[j + 1]];
              dp[i][j] = min(dp[i][j], cost);
            }
          }
        }
      }
  }
  int best = INF;
  for (int i = 0; i < k; i++)
    best = min(best, dp[(1 << k) - 1][i] + dist[i + 1][n]);
  g << best << ' ';
  return 0;
}
