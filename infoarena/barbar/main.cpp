#include <fstream>
#include <iostream>
#include <queue>
using namespace std;
#define MAXN 1010
ifstream f("barbar.in");
ofstream g("barbar.out");
queue<int> l, c;
char car;
int a[MAXN][MAXN], b[MAXN][MAXN], n, m, xi, xf, yi, yf, li, lf, ci, cf,
    dl[] = {-1, 0, 1, 0}, dc[] = {0, -1, 0, 1};
int main() {
  f >> n >> m;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      f >> car;
      if (car == 'I') {
        xi = i;
        yi = j;
      }
      if (car == '*') {
        a[i][j] = -1;
        b[i][j] = -1;
      }
      if (car == 'D') {
        l.push(i);
        c.push(j);
      }
      if (car == 'O') {
        xf = i;
        yf = j;
      }
    }
  while (l.size()) {
    li = l.front();
    ci = c.front();
    l.pop();
    c.pop();
    if (li > 0 && li <= n && ci <= m && ci > 0)
      for (int i = 0; i <= 3; i++) {
        lf = li + dl[i];
        cf = ci + dc[i];
        if (a[lf][cf] == 0) {
          a[lf][cf] = a[li][ci] + 1;
          l.push(lf);
          c.push(cf);
        }
      }
  }
  l.push(xi);
  c.push(yi);
  b[xi][yi] = a[xi][yi];
  while (l.size()) {
    li = l.front();
    ci = c.front();
    l.pop();
    c.pop();
    if (li > 0 && li <= n && ci > 0 && ci <= m)
      for (int i = 0; i <= 3; i++) {
        lf = li + dl[i];
        cf = ci + dc[i];
        if (min(b[li][ci], a[lf][cf]) > b[lf][cf]) {
          b[lf][cf] = min(b[li][ci], a[lf][cf]);
          l.push(lf);
          c.push(cf);
        }
      }
  }
  if (b[xf][yf] != 0 && b[xf][yf] != -1)
    g << b[xf][yf];
  else
    g << -1;

  return 0;
}
