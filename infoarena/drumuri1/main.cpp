#include <fstream>
#include <iostream>
using namespace std;
ifstream f("drumuri1.in");
ofstream g("drumuri1.out");
#define MAXN 252
#define MOD 31607
int x, y, m, n, k, l, dp[2][MAXN][MAXN], a[MAXN][MAXN], rez;
int main() {
  f >> n >> m >> k >> l;
  while (m--) {
    f >> x >> y;
    a[x][y] = 1;
  }
  if (a[1][1] == 1)
    dp[1][1][1] = 1;
  else
    dp[1][1][0] = 1;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) {

      if (i != 1 || j != 1) {
        if (a[i][j] == 0) {
          for (int p = 0; p <= k; p++) {
            dp[i % 2][j][p] = 0;
            dp[i % 2][j][p] =
                (dp[(i - 1) % 2][j][p] + dp[i % 2][j - 1][p]) % MOD;
          }
        } else {
          dp[i % 2][j][0] = 0;
          for (int p = 1; p <= k; p++) {
            dp[i % 2][j][p] = 0;
            dp[i % 2][j][p] =
                (dp[(i - 1) % 2][j][p - 1] + dp[i % 2][j - 1][p - 1]) % MOD;
          }
        }
      }
      if (i + j == l + 1) {
        rez += dp[i % 2][j][k];
        rez %= MOD;
      }
    }
  g << rez;
  return 0;
}
