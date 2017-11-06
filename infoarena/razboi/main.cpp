#include <fstream>
#include <iostream>
#include <vector>
using namespace std;
#define MAXN 16010
#define ll long long
#define INF 1900000000
ifstream f("razboi.in");
ofstream g("razboi.out");
vector<pair<int, int>> G[MAXN];
struct {
  ll max1;
  ll max2;
  ll nr1;
  ll nr2;
} sub[MAXN];
int viz[MAXN], x, y, c, n, t;
ll dp[MAXN], minim;
void dfs(int nod) {
  viz[nod] = 1;
  sub[nod].max1 = sub[nod].max2 = sub[nod].nr1 = sub[nod].nr2 = 0;
  for (auto y : G[nod]) {
    int x = y.first;
    if (!viz[x]) {
      dfs(x);
      if (sub[x].max1 + y.second > sub[nod].max1) {
        sub[nod].max2 = sub[nod].max1;
        sub[nod].nr2 = sub[nod].nr1;
        sub[nod].nr1 = x;
        sub[nod].max1 = sub[x].max1 + y.second;
      } else if (sub[x].max1 + y.second > sub[nod].max2) {
        sub[nod].nr2 = x;
        sub[nod].max2 = sub[x].max1 + y.second;
      }
    }
  }
}
void solve(int nod) {
  viz[nod] = 1;
  for (auto y : G[nod]) {
    int x = y.first;
    if (!viz[x]) {
      if (x != sub[nod].nr1) {
        dp[x] = max(dp[x], max(dp[nod] + y.second, sub[nod].max1 + y.second));
      } else if (sub[nod].nr2 != 0) {
        dp[x] = max(dp[x], max(dp[nod] + y.second, sub[nod].max2 + y.second));
      } else {
        dp[x] = max(dp[x], dp[nod] + y.second);
      }
      solve(x);
    }
  }
}
int main() {
  f >> t;
  for (int j = 1; j <= t; j++) {
    f >> n;
    for (int i = 1; i < n; i++) {
      f >> x >> y >> c;
      G[x].push_back(make_pair(y, c));
      G[y].push_back(make_pair(x, c));
    }
    dfs(1);
    for (int i = 1; i <= n; i++)
      viz[i] = 0;
    solve(1);
    minim = INF;
    g << "Testul nr #" << j << '\n';
    for (int i = 1; i <= n; i++)
      minim = min(minim, max(sub[i].max1, dp[i]));
    for (int i = 1; i <= n; i++)
      if (max(sub[i].max1, dp[i]) == minim)
        g << i << '\n';

    for (int i = 1; i <= n; i++) {
      viz[i] = sub[i].max1 = sub[i].max2 = sub[i].nr1 = sub[i].nr2 = dp[i] = 0;
      G[i].clear();
    }
  }
  return 0;
}
