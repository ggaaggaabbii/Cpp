#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
using namespace std;
#define MAXN 120010
ifstream f("infasuratoare.in");
ofstream g("infasuratoare.out");
struct pct {
  double x, y;
} P[MAXN];
double det(pct a, pct b, pct c) {
  return a.x * b.y + c.x * a.y + b.x * c.y - c.x * b.y - a.x * c.y - a.y * b.x;
}
bool cmp(pct a, pct b) { return det(P[0], a, b) > 0; }
int n, minim = 0, st[MAXN], vf;
int main() {
  f >> n;
  for (int i = 0; i < n; i++) {
    f >> P[i].x >> P[i].y;
    if (P[i].x < P[minim].x)
      minim = i;
    else if (P[i].x == P[minim].x && P[i].y < P[minim].y)
      minim = i;
  }
  swap(P[0], P[minim]);
  sort(P + 1, P + n, cmp);
  P[n] = P[0];
  st[0] = 0;
  st[1] = 1;
  vf = 1;
  for (int i = 2; i <= n; i++) {
    while (vf > 0 && det(P[st[vf - 1]], P[st[vf]], P[i]) < 0)
      vf--;
    st[++vf] = i;
  }
  g << vf << '\n';
  for (int i = 1; i <= vf; i++)
    g << fixed << setprecision(6) << P[st[i]].x << ' ' << P[st[i]].y << '\n';
  return 0;
}
