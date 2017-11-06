#include <fstream>
#include <iostream>
#include <vector>
using namespace std;
#define MAXN 110
#define MOD 30011
vector<int> G[MAXN];
ifstream f("iepuri2.in");
ofstream g("iepuri2.out");
int viz[MAXN], nrpos[MAXN], gr[MAXN], gre[MAXN], root, k, x, y, n, ok,
    valmax[MAXN], rez, dp[MAXN][MAXN], niv[MAXN];
void dfs(int nod) {
  for (auto it : G[nod])
    dfs(it);
  for (int i = k; i >= 1; i--) {
    dp[nod][i] = 1;
    for (auto it : G[nod]) {
      dp[it][i + 1] += dp[it][i + 2];
      dp[it][i + 1] %= MOD;
      long t = dp[nod][i];
      t *= dp[it][i + 1];
      dp[nod][i] = t % MOD;
    }
  }
}
int main() {
  f >> n >> k;
  for (int i = 1; i < n; i++) {
    f >> x >> y;
    G[x].push_back(y);
    gr[y]++;
    gre[x]++;
  }
  for (int i = 1; i <= n; i++) {
    if (gr[i] == 0) {
      root = i;
      break;
    }
  }
  dfs(root);
  /*for(int i=1; i<=n; i++)
  {
      for(int j=1; j<=2*k; j++)
          cout<<dp[i][j]<<' ';
      cout<<endl;
  }*/
  for (int i = 1; i <= n; i++) {
    rez = (rez + dp[root][i]) % MOD;
  }
  g << rez;
  return 0;
}
