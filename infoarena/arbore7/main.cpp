#include <fstream>
#include <iostream>
#include <vector>
using namespace std;
#define MAXN 100010
#define MOD 1000000007
ifstream f("arbore7.in");
ofstream g("arbore7.out");
vector<int> G[MAXN];
int v[2][MAXN], n, x, y, viz[MAXN], maxim;
long long dp[2][MAXN];
void dfs(int nod) {
  viz[nod] = 1;
  v[1][nod] = 1;
  dp[0][nod] = dp[1][nod] = 1;
  for (auto y : G[nod]) {
    if (!viz[y]) {
      dfs(y);
      v[0][nod] += max(v[0][y], v[1][y]);
      if (v[0][y] >= v[1][y] - 1) {
        v[1][nod] += v[0][y];
      } else {
        v[1][nod] = v[1][nod] + v[1][y] - 1;
      }
      if (v[0][y] == v[1][y]) {
        dp[0][nod] *= (dp[0][y] + dp[1][y]);
        dp[0][nod] %= MOD;
      }
      if (v[0][y] == v[1][y] - 1) {
        dp[1][nod] *= (dp[0][y] + dp[1][y]);
        dp[1][nod] %= MOD;
      }
      if (v[0][y] > v[1][y]) {
        dp[0][nod] *= dp[0][y];
        dp[0][nod] %= MOD;
      }
      if (v[0][y] > v[1][y] - 1) {
        dp[1][nod] *= dp[0][y];
        dp[1][nod] %= MOD;
      }
      if (v[0][y] < v[1][y]) {
        dp[0][nod] *= dp[1][y];
        dp[0][nod] %= MOD;
      }
      if (v[0][y] < v[1][y] - 1) {
        dp[1][nod] *= dp[1][y];
        dp[1][nod] %= MOD;
      }
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
  maxim = max(v[1][1], v[0][1]);
  g << maxim << ' ';
  if (v[0][1] == v[1][1])
    g << (dp[0][1] + dp[1][1]) % MOD;
  else if (v[0][1] > v[1][1])
    g << dp[0][1];
  else
    g << dp[1][1];
  return 0;
}
