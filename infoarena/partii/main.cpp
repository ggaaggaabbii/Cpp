#include <fstream>
#include <iostream>
#include <vector>
using namespace std;
#define MAXN 1010
ifstream f("partii.in");
ofstream g("partii.out");
struct partie {
  int sus = 0, jos = 0, st = 0, dr = 0;
} mat[MAXN][MAXN];
int a[MAXN][MAXN], n, m, s, maxim;
int main() {
  f >> n >> m;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j)
      f >> a[i][j];
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) {
      if (i > 1 && a[i][j] > a[i - 1][j])
        mat[i][j].sus = mat[i - 1][j].sus + 1;
      if (j > 1 && a[i][j] > a[i][j - 1])
        mat[i][j].st = mat[i][j - 1].st + 1;
    }
  for (int i = n; i > 0; --i)
    for (int j = m; j > 0; --j) {
      if (i < n && a[i][j] > a[i + 1][j])
        mat[i][j].jos = mat[i + 1][j].jos + 1;
      if (j < m && a[i][j] > a[i][j + 1])
        mat[i][j].dr = mat[i][j + 1].dr + 1;
    }
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) {
      s = mat[i][j].sus + mat[i][j].jos + mat[i][j].dr + mat[i][j].st + 1;
      maxim = max(maxim, s);
    }
  g << maxim;
  return 0;
}
