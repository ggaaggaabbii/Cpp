#include <fstream>
#include <iostream>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
#define MAXN 1030
int n, m, v[MAXN], w[MAXN], a[MAXN][MAXN], sir[MAXN], nr;
void drum(int x, int y) {
  if (x > 0 && y > 0) {
    if (v[x] == w[y]) {
      sir[++nr] = v[x];
      drum(x - 1, y - 1);
    } else if (a[x - 1][y] > a[x][y - 1])
      drum(x - 1, y);
    else
      drum(x, y - 1);
  }
}
int main() {
  f >> n >> m;
  for (int i = 1; i <= n; i++)
    f >> v[i];
  for (int i = 1; i <= m; i++)
    f >> w[i];
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (v[i] == w[j])
        a[i][j] = a[i - 1][j - 1] + 1;
      else
        a[i][j] = max(a[i - 1][j], a[i][j - 1]);
    }
  }
  drum(n, m);
  g << a[n][m] << '\n';
  for (int i = a[n][m]; i >= 1; i--)
    g << sir[i] << ' ';

  return 0;
}
