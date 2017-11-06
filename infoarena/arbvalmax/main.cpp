#include <fstream>
#include <iostream>
#include <vector>
using namespace std;
#define MAXN 300010
ifstream f("arbvalmax.in");
ofstream g("arbvalmax.out");
vector<int> G[MAXN];
int viz[MAXN], n, q, x, a, b;
long val[MAXN], dp[MAXN], dp1[MAXN];
struct {
  long max1, max2, nr1, nr2;
} sub[MAXN];
void dfs(int nod) {
  viz[nod] = 1;
  for (auto y : G[nod]) {
    if (!viz[y]) {
      dfs(y);
      if (sub[y].max1 > sub[nod].max1 || val[y] > sub[nod].max1) {
        sub[nod].max2 = sub[nod].max1;
        sub[nod].nr2 = sub[nod].nr1;
        sub[nod].max1 = max(val[y], sub[y].max1);
        sub[nod].nr1 = y;
      } else if (sub[y].max1 > sub[nod].max2 || val[y] > sub[nod].max2) {
        sub[nod].max2 = max(sub[y].max1, val[y]);
        sub[nod].nr2 = y;
      }
    }
  }
}
void solve(int nod) {
  viz[nod] = 1;
  for (auto y : G[nod]) {
    if (!viz[y]) {
      if (y != sub[nod].nr1) {
        dp[y] = max(dp[y], max(dp[nod], max(val[nod], sub[nod].max1)));
        dp1[y] = max(dp1[nod], sub[nod].max1);
      } else {
        dp[y] = max(dp[y], max(dp[nod], max(val[nod], sub[nod].max2)));
        dp1[y] = max(dp1[nod], sub[nod].max2);
      }
      solve(y);
    }
  }
}
int main() {
  f >> n >> q;
  for (int i = 1; i < n; i++) {
    f >> x;
    G[x].push_back(i + 1);
    G[i + 1].push_back(x);
  }
  for (int i = 1; i <= n; i++)
    f >> val[i];
  dfs(1);
  /*cout<<endl;
  for(int i=1;i<=n;i++)
      cout<<sub[i].max1<<' '<<sub[i].nr1<<' '<<sub[i].max2<<'
  '<<sub[i].nr2<<'\n';*/
  for (int i = 1; i <= n; i++)
    viz[i] = 0;
  solve(1);
  /*for(int i=1;i<=n;i++)
  cout<<dp[i]<<'\n';
  cout<<'\n';*/
  for (int i = 1; i <= q; i++) {
    f >> a >> b;
    g << max(dp[a], max(dp1[b], sub[b].max1)) << '\n';
  }
  return 0;
}
