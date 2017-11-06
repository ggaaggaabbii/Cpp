#include <cmath>
#include <fstream>
#include <iostream>
using namespace std;
ifstream f("damesah.in");
ofstream g("damesah.out");
int v[20], n, ok, l[20], c[20], d[50], d2[50];
int nr = 1;
void afis() {
  for (int i = 1; i <= n; i++)
    g << v[i] << ' ';
  g << '\n';
}
void bktr(int pas) {
  if (pas == n + 1) {
    if (ok == 0) {
      afis();
      ok = 1;
    } else
      nr++;
  }
  for (int i = 1; i <= n; i++) {
    v[pas] = i;
    if (!c[i] && !l[pas] && !d[i - pas + n] && !d2[pas + i]) {
      l[pas] = c[i] = d[i - pas + n] = d2[pas + i] = 1;
      bktr(pas + 1);
      l[pas] = c[i] = d[i - pas + n] = d2[pas + i] = 0;
    }
  }
}
int main() {
  f >> n;
  bktr(1);
  g << nr;
  return 0;
}
