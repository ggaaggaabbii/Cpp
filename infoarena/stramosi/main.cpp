#include <fstream>
#include <iostream>
using namespace std;
ifstream f("stramosi.in");
ofstream g("stramosi.out");
int a[18][250002], i, j, n, m, k, nr, pct;
int str(int nod, int p) {
  int i = 0;
  while (p != 0) {
    if (p % 2)
      nod = a[i][nod];
    p /= 2;
    i++;
  }
  return nod;
}
int main() {
  f >> n >> m;
  for (i = 1; i <= n; i++)
    f >> a[0][i];
  for (i = 1; (1 << i) <= n; i++)
    for (j = 1; j <= n; j++)
      if (a[i - 1][j])
        a[i][j] = a[i - 1][a[i - 1][j]];
  for (k = 1; k <= m; k++) {
    f >> pct >> nr;
    g << str(pct, nr) << '\n';
  }
  return 0;
}
