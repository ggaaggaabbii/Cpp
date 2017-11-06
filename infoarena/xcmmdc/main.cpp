#include <fstream>
#include <iostream>
#define MAXN 1010
#define MAXLG 12
using namespace std;
ifstream f("xcmmdc.in");
ofstream g("xcmmdc.out");
int rmq[MAXLG][MAXN][MAXN], a[MAXN][MAXN], n, m, k, q, lg[MAXN], poz1, poz2,
    mij, val, ad1, ad2, rez[MAXN], x, pow, lim, l, nexti, nextj, c;
int cmmdc(int a, int b) {
  int r;
  while (b) {
    r = a % b;
    a = b;
    b = r;
  }
  return a;
}
int main() {
  f >> n >> m >> k >> q;
  lim = min(n, m);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      f >> a[i][j];
      rmq[0][i][j] = a[i][j];
    }
  for (int i = 2; i <= n || i <= m; i++)
    lg[i] = lg[i >> 1] + 1;
  pow = 1;
  for (int k = 1; k <= lg[lim]; ++k, pow <<= 1)
    for (int i = 1; i <= n; ++i)
      if (i + pow <= n)
        for (int j = 1; j <= m; ++j)
          if (j + pow <= m)
            rmq[k][i][j] =
                cmmdc(cmmdc(rmq[k - 1][i + pow][j], rmq[k - 1][i][j + pow]),
                      cmmdc(rmq[k - 1][i][j], rmq[k - 1][i + pow][j + pow]));
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) {
      poz1 = 1;
      poz2 = min(n - i + 1, m - j + 1);
      ad1 = 0;
      ad2 = 0;
      while (poz1 <= poz2) {
        mij = (poz1 + poz2) / 2;
        l = lg[mij];
        pow = 1 << l;
        nexti = i + mij - pow;
        nextj = j + mij - pow;
        val = cmmdc(cmmdc(rmq[l][i][j], rmq[l][nexti][j]),
                    cmmdc(rmq[l][i][nextj], rmq[l][nexti][nextj]));
        if (val > k) {
          poz1 = mij + 1;
          ad1 = mij;
        } else
          poz2 = mij - 1;
      }
      ad1++;
      poz1 = 1;
      poz2 = min(n - i + 1, m - j + 1);
      while (poz1 <= poz2) {
        mij = (poz1 + poz2) / 2;
        l = lg[mij];
        pow = 1 << l;
        nexti = i + mij - pow;
        nextj = j + mij - pow;
        val = cmmdc(cmmdc(rmq[l][i][j], rmq[l][nexti][j]),
                    cmmdc(rmq[l][i][nextj], rmq[l][nexti][nextj]));
        if (val >= k) {
          poz1 = mij + 1;
          ad2 = mij;
        } else
          poz2 = mij - 1;
      }
      if (ad1 <= ad2) {
        rez[ad1]++;
        rez[ad2 + 1]--;
      }
    }
  for (int i = 1; i <= lim; i++)
    rez[i] += rez[i - 1];
  while (q--) {
    f >> x;
    g << rez[x] << '\n';
  }
  return 0;
}
