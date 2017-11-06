#include <fstream>
#include <iostream>
#include <vector>
using namespace std;
#define MAXN 100010
#define MOD 666013
ifstream f("arbore4.in");
ofstream g("arbore4.out");
long long putere(long long a, int nr) {
  if (nr == 0)
    return 1;
  long long c = putere(a, nr / 2);
  c *= c;
  c %= MOD;
  if (nr % 2 == 0)
    return c;
  return (c * a) % MOD;
}
vector<int> G[MAXN];
long long fact[MAXN], inv[MAXN], dp[MAXN];
int weight[MAXN], viz[MAXN], viz2[MAXN];
int n, x, y;
void dfs(int nod) {
  viz[nod] = 1;
  int nr = G[nod].size();
  int ok = 0;
  for (auto it : G[nod]) {
    if (!viz[it]) {
      dfs(it);
      weight[nod] += weight[it];
    }
  }
  weight[nod]++;
}
void solve(int nod) {
  viz2[nod] = 1;
  int nr = weight[nod] - 1;
  for (auto it : G[nod]) {
    if (!viz2[it]) {
      solve(it);
      dp[nod] *= dp[it];
      dp[nod] %= MOD;
      dp[nod] *= (fact[nr] * inv[nr - weight[it]] * inv[weight[it]]) % MOD;
      dp[nod] %= MOD;
      nr -= weight[it];
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
  fact[0] = 1;
  inv[0] = 1;
  for (int i = 1; i <= n; i++)
    dp[i] = 1;
  for (int i = 1; i <= n; i++) {
    fact[i] = (fact[i - 1] * i) % MOD;
    inv[i] = putere(fact[i], MOD - 2);
  }
  dfs(1);
  solve(1);
  g << dp[1];
  return 0;
}
