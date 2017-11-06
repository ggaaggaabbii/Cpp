#include <fstream>
#include <iostream>
using namespace std;
int v[280000], n, mu, a, b, maxim, o;
ifstream f("arbint.in");
ofstream g("arbint.out");
void update(int nr, int l, int r) {
  if (l == r) {
    v[nr] = b;
    return;
  }
  int m = (l + r) / 2;
  if (a <= m)
    update(2 * nr, l, m);
  else
    update(2 * nr + 1, m + 1, r);
  v[nr] = max(v[2 * nr], v[2 * nr + 1]);
}
void query(int nr, int l, int r) {
  if (a <= l && b >= r) {
    if (v[nr] >= maxim)
      maxim = v[nr];
    return;
  }
  int m = (l + r) / 2;
  if (a <= m)
    query(2 * nr, l, m);
  if (m < b)
    query(2 * nr + 1, m + 1, r);
}
int main() {
  f >> n >> mu;
  for (a = 1; a <= n; a++) {
    f >> b;
    update(1, 1, n);
  }
  while (mu--) {
    f >> o >> a >> b;
    if (o == 0) {
      maxim = -1;
      query(1, 1, n);
      g << maxim << '\n';
    } else
      update(1, 1, n);
  }
  return 0;
}
