#include <fstream>
#include <iostream>
using namespace std;
ifstream f("datorii.in");
ofstream g("datorii.out");
int n, m, v[280000], sum, a, b, o;
void update(int nod, int l, int r) {
  v[nod] += b;
  if (l == r)
    return;
  int mij = (l + r) / 2;
  if (a <= mij)
    update(2 * nod, l, mij);
  else
    update(2 * nod + 1, mij + 1, r);
}
void query(int nod, int l, int r) {
  if (a <= l && b >= r) {
    sum += v[nod];
    return;
  }
  int mij = (l + r) / 2;
  if (a <= mij)
    query(2 * nod, l, mij);
  if (b > mij)
    query(2 * nod + 1, mij + 1, r);
}
int main() {
  f >> n >> m;
  for (a = 1; a <= n; a++) {
    f >> b;
    update(1, 1, n);
  }
  while (m--) {
    f >> o >> a >> b;
    if (o == 0) {
      b = -b;
      update(1, 1, n);
    } else {
      sum = 0;
      query(1, 1, n);
      g << sum << '\n';
    }
  }
  return 0;
}
