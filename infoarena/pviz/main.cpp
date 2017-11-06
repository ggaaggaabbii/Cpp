#include <fstream>
#include <iostream>
#define MAXN 2010
#define MOD 10007
using namespace std;
ifstream f("pviz.in");
ofstream g("pviz.out");
int a[MAXN][MAXN], v[MAXN], n, m;
int main() {
  f >> n >> m;
  for (int i = 1; i <= m; i++)
    f >> v[i];
  a[0][0] = 1;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      a[i][j] = (a[i - 1][j - 1] + (v[j] - i + 1) * a[i - 1][j]) % MOD;
  g << a[n][m];
  return 0;
}
