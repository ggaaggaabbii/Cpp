#include <fstream>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define MAXN 210
ifstream f("cartite.in");
ofstream g("cartite.out");
queue<int> L, C;
pair<int, int> Gr[MAXN];
vector<int> G[MAXN];
int a[MAXN][MAXN], b[MAXN][MAXN], me, xn, yn, x1, y1, x2, y2, xc, nr, yc, x, y,
    c, p, n, m, xi, yi, k, dl[] = {-1, 0, 1, 0}, dc[] = {0, -1, 0, 1};
void umple(int x, int y, int c) {
  a[x][y] = -1;
  if (c > 0)
    for (int i = 0; i <= 3; i++)
      if (x + dl[i] > 0 && x + dl[i] <= n && y + dc[i] > 0 && y + dc[i] <= n)
        a[x + dl[i]][y + dc[i]] = a[x][y];
  if (c > 1) {
    for (int i = 0; i <= 3; i++)
      if (x + 2 * dl[i] > 0 && x + 2 * dl[i] <= n && y + 2 * dc[i] > 0 &&
          y + 2 * dc[i] <= m)
        a[x + 2 * dl[i]][y + 2 * dc[i]] = a[x][y];
    if (x + 1 <= n && y + 1 <= m)
      a[x + 1][y + 1] = a[x][y];
    if (x + 1 <= n && y - 1 > 0)
      a[x + 1][y - 1] = a[x][y];
    if (x - 1 > 0 && y - 1 > 0)
      a[x - 1][y + 1] = a[x][y];
    if (x - 1 > 0 && y + 1 <= m)
      a[x - 1][y + 1] = a[x][y];
  }
}
void euler(int nod) {
  int urm;
  while (G[nod].size()) {
    urm = G[nod].back();
    G[nod].pop_back();
    for (auto &it : G[urm])
      if (it == nod) {
        swap(it, G[urm].back());
        G[urm].pop_back();
        break;
      }
    euler(urm);
  }
  g << Gr[nod].first << ' ' << Gr[nod].second << '\n';
}
int main() {
  f >> p >> n >> m >> xi >> yi >> k;
  while (k--) {
    f >> x >> y >> c;
    umple(x, y, c);
  }
  f >> me;
  while (me--) {
    f >> x1 >> y1 >> x2 >> y2;
    if (a[x1][y1] == 0)
      a[x1][y2] = -2;
    if (a[x2][y2] == 0)
      a[x2][y2] = -2;
    if (!b[x1][y1]) {
      Gr[++nr] = make_pair(x1, y1);
      b[x1][y1] = nr;
    }
    if (!b[x2][y2]) {
      Gr[++nr] = make_pair(x2, y2);
      b[x2][y2] = nr;
    }
    G[b[x1][y1]].push_back(b[x2][y2]);
    G[b[x2][y2]].push_back(b[x1][y1]);
  }
  if (p == 1) {
    L.push(xi);
    C.push(yi);
    while (L.size()) {
      xc = L.front();
      yc = C.front();
      L.pop();
      C.pop();
      if (xc > 0 && xc <= n && yc > 0 && yc <= m) {
        for (int i = 0; i <= 3; i++) {
          xn = xc + dl[i];
          yn = yc + dc[i];
          if (a[xn][yn] == 0) {
            L.push(xn);
            C.push(yn);
            a[xn][yn] = a[xc][yc] + 1;
          }
          if (a[xn][yn] == -2) {
            g << xn << ' ' << yn << ' ' << a[xc][yc] + 1;
            return 0;
          }
        }
      }
    }
  } else {
    for (int i = 1; i <= n; i++)
      if (a[Gr[i].first][Gr[i].second] != -1) {
        euler(i);
        break;
      }
  }
  return 0;
}
