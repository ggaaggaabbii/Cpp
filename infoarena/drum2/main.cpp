#include <fstream>
#include <iostream>
#define MAXN 32
using namespace std;
ifstream f("drum2.in");
ofstream g("drum2.out");
int a[MAXN][MAXN][MAXN], n, pct[MAXN][MAXN][MAXN], nr;
void drum(int k, int i, int j) {
  if (a[k][i][j] == 0)
    return;
  g << pct[k][i][j] << ' ';
  if (a[k + 1][i][j + 1] >= a[k + 1][i + 1][j + 1] &&
      a[k + 1][i][j + 1] >= a[k + 1][i + 1][j]) {
    drum(k + 1, i, j + 1);
    return;
  }
  if (a[k + 1][i + 1][j] >= a[k + 1][i + 1][j + 1]) {
    drum(k + 1, i + 1, j);
    return;
  }
  drum(k + 1, i + 1, j + 1);
}
int main() {
  f >> n;
  for (int k = 1; k <= n; ++k)
    for (int i = 1; i <= k; ++i)
      for (int j = 1; j <= k; ++j) {
        f >> a[k][i][j];
        pct[k][i][j] = ++nr;
      }
  for (int k = n - 1; k >= 1; --k)
    for (int i = 1; i <= k; ++i)
      for (int j = k - i + 1; j <= k; ++j)
        a[k][i][j] += max(a[k + 1][i + 1][j],
                          max(a[k + 1][i + 1][j + 1], a[k + 1][i][j + 1]));
  g << a[1][1][1] << '\n';
  drum(1, 1, 1);
  return 0;
}
