#include <bitset>
#include <cmath>
#include <fstream>
#include <iostream>
#include <queue>
#include <vector>
#define MAXN 110
using namespace std;
ifstream f("lacuri.in");
ofstream g("lacuri.out");
int a[MAXN][MAXN], n, dl[] = {-1, 0, 1, 0}, dc[] = {0, -1, 0, 1}, contor, nr,
                      rad, lac, x, y, ok, ki, k;
bitset<MAXN> viz[MAXN];
short L[MAXN * MAXN], C[MAXN * MAXN];
vector<pair<short, short>> v;
void umple(short x, short y) {
  short xc, yc, xn, yn;
  k = 0;
  ki = 1;
  L[++k] = x;
  C[k] = y;
  viz[x][y] = 1;
  while (ki <= k) {
    xc = L[ki];
    yc = C[ki];
    if (xc > 0 && yc > 0 && xc <= n && yc <= n) {
      viz[xc][yc] = 1;
      contor++;
      for (short i = 0; i <= 3; i++) {
        xn = xc + dl[i];
        yn = yc + dc[i];
        if (a[xn][yn] == -1 && viz[xn][yn] == 0) {
          viz[xn][yn] = 1;
          L[++k] = xn;
          C[k] = yn;
        }
      }
    }
    ki++;
  }
}
void lee() {
  short xc, yc, xn, yn;
  k = 0;
  ki = 1;
  L[++k] = 1;
  C[k] = 1;
  while (ki <= k) {
    xc = L[ki];
    yc = C[ki];
    if (xc > 0 && yc > 0 && xc <= n && yc <= n) {
      for (short i = 0; i <= 3; i++) {
        xn = xc + dl[i];
        yn = yc + dc[i];
        if (a[xn][yn] == 0) {
          a[xn][yn] = a[xc][yc] + 1;
          L[++k] = xn;
          C[k] = yn;
        }
      }
    }
    ki++;
  }
}
int main() {
  f >> n;
  for (short i = 1; i <= n; i++)
    for (short j = 1; j <= n; j++) {
      f >> a[i][j];
      if (a[i][j] == 1)
        a[i][j] = -1;
    }
  for (short i = 1; i <= n; i++)
    for (short j = 1; j <= n; j++) {
      if (a[i][j] == -1 && viz[i][j] == 0) {
        lac++;
        contor = 0;
        umple(i, j);
        rad = sqrt(contor);
        if (rad * rad == contor) {
          ok = 1;
          for (short p = i; p <= i + rad - 1; p++)
            for (short q = j; q <= j + rad - 1; q++)
              if (a[p][q] == 0) {
                ok = 0;
                break;
              }
          if (ok == 1)
            nr++;
        }
      }
    }
  g << nr << '\n';
  if (lac == nr) {
    a[1][1] = 1;
    lee();
    x = y = n;
    while (a[x][y] != 0 && a[x][y] != 1) {
      v.push_back(make_pair(x, y));
      if (a[x - 1][y] == a[x][y] - 1)
        x--;
      else if (a[x + 1][y] == a[x][y] - 1)
        x++;
      else if (a[x][y - 1] == a[x][y] - 1)
        y--;
      else
        y++;
    }
    g << 1 << ' ' << 1 << '\n';
    for (short i = v.size() - 1; i >= 0; i--)
      g << v[i].first << ' ' << v[i].second << '\n';
  }
  return 0;
}
