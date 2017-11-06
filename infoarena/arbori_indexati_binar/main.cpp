#include <fstream>
#include <iostream>
using namespace std;
#define MAXN 100010
ifstream f("aib.in");
ofstream g("aib.out");
int aib[MAXN], n, m, c, x, y, poz;
void update(int pos, int val) {
  for (; pos <= n; pos += pos & (-pos))
    aib[pos] += val;
}
int query(int pos) {
  int rez = 0;
  for (; pos > 0; pos -= pos & (-pos))
    rez += aib[pos];
  return rez;
}
int caut(int val) {
  int step = 1, pos = 0;
  for (; step <= n; step <<= 1)
    ;
  for (; step > 0; step >>= 1) {
    if (pos + step <= n) {
      if (aib[pos + step] <= val) {
        val -= aib[pos + step];
        pos += step;
      }
    }
  }
  return pos;
}
int main() {
  f >> n >> m;
  for (int i = 1; i <= n; i++) {
    f >> x;
    update(i, x);
  }
  for (int i = 1; i <= m; i++) {
    f >> c;
    if (c == 0) {
      f >> x >> y;
      update(x, y);
    } else if (c == 1) {
      f >> x >> y;
      g << query(y) - query(x - 1) << '\n';
    } else {
      f >> x;
      poz = caut(x - 1);
      if (query(poz + 1) == x)
        g << poz + 1 << '\n';
      else
        g << "-1\n";
    }
  }
  return 0;
}
