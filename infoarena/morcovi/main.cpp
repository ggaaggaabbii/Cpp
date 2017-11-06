#include <fstream>
#include <iostream>
#define MAXN 1010
#define MAXP 12
using namespace std;
ifstream f("morcovi.in");
ofstream g("morcovi.out");
int dp[(1 << MAXP) + 10][MAXN], n, p, pas[MAXP + 10], maxim;
int main() {
  f >> n;
  for (int i = 1; i <= n; i++)
    f >> dp[0][i];
  f >> p;
  for (int i = 0; i < p; i++)
    f >> pas[i];
  for (int i = 0; i < (1 << p); ++i)
    for (int j = 0; j < p; ++j)
      if ((i & (1 << j)))
        for (int k = 1; k <= n; ++k) {
          if (k - pas[j] > 0)
            dp[i][k] = max(dp[i - (1 << j)][k - pas[j]] + dp[0][k], dp[i][k]);
          if (k + pas[j] <= n)
            dp[i][k] = max(dp[i][k], dp[i - (1 << j)][k + pas[j]] + dp[0][k]);
          maxim = max(maxim, dp[i][k]);
        }
  g << maxim;
  return 0;
}
