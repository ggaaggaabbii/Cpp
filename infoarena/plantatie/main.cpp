#include <fstream>
#include <iostream>
#define MAXN 510
#define MAXLG 12
using namespace std;
ifstream f("plantatie.in");
ofstream g("plantatie.out");
int rmq[MAXLG][MAXN][MAXN], n, q, pow, lg[MAXN], x, y, k, l;
int main() {
  f >> n >> q;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      f >> rmq[0][i][j];
  for (int i = 2; i <= n; i++)
    lg[i] = lg[i >> 1] + 1;
  pow = 1;
  for (int k = 1; k <= lg[n]; ++k, pow <<= 1)
    for (int i = 1; i + pow <= n; i++)
      for (int j = 1; j + pow <= n; j++)
        rmq[k][i][j] =
            max(max(rmq[k - 1][i][j], rmq[k - 1][i + pow][j]),
                max(rmq[k - 1][i + pow][j + pow], rmq[k - 1][i][j + pow]));
  while (q--) {
    f >> x >> y >> k;
    l = k;
    k = lg[k];
    pow = (1 << k);
    g << max(max(rmq[k][x][y], rmq[k][x + l - pow][y]),
             max(rmq[k][x + l - pow][y + l - pow], rmq[k][x][y + l - pow]))
      << '\n';
  }
  return 0;
}
